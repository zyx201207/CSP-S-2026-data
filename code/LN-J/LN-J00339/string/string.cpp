#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t,n;cin>>t;
    string a,s="";
    while(t--){
        cin>>n>>a;
        for(int i=1;i<=n;i++)s+=a;
    }
    ll d=s.size()/2,ans=0;
    string c="",h="";
    for(int i=0;i<d;i++){
        c+=s[i];
    }
    int b=s.size();
    if(b%2==0){
        for(int i=b-1;i>=d;i--)h+=s[i];
    }else{
        for(int i=s.size()-1;i>d;i--)h+=s[i];
    }
    for(int i=0;i<h.size();i++){
        if(h[i]!=c[i])ans++;
    }
    cout<<ans;
    return 0;
}


