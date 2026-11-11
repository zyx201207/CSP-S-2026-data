#include<bits/stdc++.h>
using namespace std;
int n;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;char c;
        cin>>a>>c;
        for(int j=1;j<=a;i++) s+=c;
    }
    int l=s.size();
    long long ans=0;
    for(int i=0;i<=l/2;i++){
        if(s[i]!=s[n-i]) ans++;
    }
    cout<<ans;
    return 0;
}
