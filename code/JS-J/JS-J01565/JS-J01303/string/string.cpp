#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long x,ls;
string s,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s+='0';
    for(int i=1;i<=n;i++){
        cin>>x>>t;
        for(int j=1;j<=x;j++){
            s+=t;
        }
    }
    ls=s.size()-1;
    for(int i=1;i<=ls/2;i++){
        if (s[i]!=s[ls-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}
