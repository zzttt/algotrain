#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/*
// O(N^2)
vector<int> getResult(const string& N) { 
    int strlength = N.size();

    vector<int> pi(strlength, 0);
    for(int begin = 1; begin < strlength; begin++) {
        for(int pos = 0; pos < strlength; pos++) {
            if(N[begin + pos] != N[pos]) break;
            pi[begin+pos] = max(pi[begin+pos] , pos + 1);
        }
    }
    return pi;
}*/

// O(N + H)
vector<int> getResult(const string& N){
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while(begin + matched < m){
        if(N[begin + matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if(matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched -1];
            }
        }
    }
    return pi;
}

vector<int> getPrefixSuffix(const string& s){
    vector<int> ret, pi = getResult(s);

    int k = s.size();
    while(k > 0){
        ret.push_back(k);
        k = pi[k-1];
    }
    return ret;
}

int main(){
    string a, b;
    cin >> a;
    cin >> b;

    a = a.append(b);
    vector<int> res = getPrefixSuffix(a);

    vector<int>::iterator iter; 

    for(iter = res.end() - 1; ; iter--){
        printf("%d ", (int)*iter);
        if(iter == res.begin()) break ;
    }
    cout << endl;

    return 0;
}