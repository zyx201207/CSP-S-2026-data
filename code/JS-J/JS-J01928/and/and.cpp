#include<bits/stdc++.h>
#include<string>
using namespace std;
using ll=long long;
ll n,m,ans,a[200005];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
void dfs(ll x,ll nowv,ll cnt){
    if(x==n+1){
        if(cnt==m)ans=max(ans,nowv);
        return ;
    }
    if(cnt==m){
        ans=max(ans,nowv);
        return ;
    }
    if(cnt==0){
        nowv=a[x];
        dfs(x+1,nowv,cnt+1);
        nowv=0;
        dfs(x+1,nowv,cnt);
    }
    else{
        if(nowv+a[x]!=1<<(ll(log2(nowv+a[x])))-1)dfs(x+1,nowv&a[x],cnt+1);
        dfs(x+1,nowv,cnt);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read(),m=read();
    ll k=0;
    for(ll i=1;i<=n;i++){
        a[i]=read();
        k=max(k,a[i]);
    }
    if(m==1){
        cout<<k;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
}