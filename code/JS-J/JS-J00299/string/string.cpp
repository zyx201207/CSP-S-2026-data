#include<bits/stdc++.h>
using namespace std;
#define int long long
string ts(char a,int n){
    string s="";
    for(int i=1;i<=n;i++)
        s+=a;
    return s;
}
int ans,n,l;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        s+=ts(b,a);
    }
    l=s.size();
    for(int i=0;i<l/2;i++){
        // cout<<s[i]<<s[l-i-1]<<'\n';
        if(s[i]!=s[l-i-1])ans++;
    }
    cout<<ans;
    return 0;
}