#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        string a;
        long long b;
        cin>>b;
        cin>>a;
        for(long long j=1;j<=b;j++){
            s+=a;
        }
    }
    long long ls=s.length();
    long long  l=0,r=ls-1;
    long long cnt=0;
    while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
    return 0;
}