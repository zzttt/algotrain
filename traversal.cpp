#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int>Preorder;
vector<int>Inorder;
vector<int>Postorder;
 
void Make_Post_Order(vector<int>&inorder, int Root)
{
    if (Preorder.empty() || inorder.empty()) return;
    Root = Preorder[0];
    Preorder.erase(Preorder.begin());
 
    vector<int>::iterator iter = find(inorder.begin(), inorder.end(), Root);
    vector<int>Left, Right;
    Left.assign(inorder.begin(), iter);
    Right.assign(iter + 1, inorder.end());
 
    Make_Post_Order(Left, Root);
    Make_Post_Order(Right, Root);
    Postorder.push_back(Root);
}
 
int main()
{
    int For_Count;
    cin >> For_Count;
 
    for (int i = 0; i < For_Count; i++)
    {
        int Node_Count;
        cin >> Node_Count;
 
        Preorder = vector<int>(Node_Count);
        Inorder = vector<int>(Node_Count);
 
        for (int j = 0; j < Node_Count; j++)
        {
            cin >> Preorder[j];
        }
        for (int j = 0; j < Node_Count; j++)
        {
            cin >> Inorder[j];
        }
 
        Make_Post_Order(Inorder, 0);
 
        for (int j = 0; j < Postorder.size(); j++)
            cout << Postorder[j] << " ";
        
        cout << endl;
 
        Postorder.clear();
    }
}