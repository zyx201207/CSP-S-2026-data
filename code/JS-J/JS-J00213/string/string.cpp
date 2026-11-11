#include<bits/stdc++.h>
using namespace std;
int n;
long long a;
int ans=0;
string s;
string S;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>s;
        for(long long j=0;j<a;j++){
            S+=s;
        }
    }
    for(long long i=0;i<S.size()/2;i++){
        if(S[i]!=S[S.size()-i-1]){
            ans++;
        }
    }cout<<ans;
}









//g++ -std=c++14 -Wall -Wextra -o XXX XXX.cpp

