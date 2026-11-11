#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; ll a[200010],b[200010];
char c[200010],d[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    ll L=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i],b[n-i+1]=a[i],d[n-i+1]=c[i];
    }
    for(int i=1;i<=n;i++) a[i]+=a[i-1],b[i]+=b[i-1];
    ll cur=0,ans=0;
    for(int i=1,j=1;;){
        ll lst=cur;
        cur=min(a[i],b[j]);
        ll len=min(cur,L/2)-lst;
        if(c[i]!=d[j]) ans+=len;
        if(cur>=L/2) break;
        if(a[i]==cur) ++i;
        if(b[j]==cur) ++j;
    }
    cout<<ans;
    return 0;
}