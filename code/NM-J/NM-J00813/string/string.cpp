#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S = "";
    long long a,numb;
    string s1;
    long long sum=0;
    cin >> a;
    for(long long i=0;i<a;i++){
        cin >> numb >> s1;
        for(long long j=0;j<numb;j++){
            S += s1;
        }
    }
    long long b = S.size() - 1;
    for(long long i=0;i<S.size()/2;i++){
            if(S[i] != S[b]){
                sum++;
                b--;
            }
    }
    cout << sum;
    return 0;}
