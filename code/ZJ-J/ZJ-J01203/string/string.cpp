#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;cin>>n;
    string s="";
    for(long long i=0;i<n;i++){
        cin>>a[i];
        string x;cin>>x;
        for(long long j=1;j<=a[i];j++){
            s+=x;
        }
    }
    long long cnt=0;
    long long length=s.size();
    for(long long i=0;i<length/2;i++){
        if(s[i]!=s[length-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}