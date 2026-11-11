#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000005
ll read(){
    ll f=0,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        f|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
ll n,D,a[N],nxt[N],pre[N],f[N],g[N];
void solve(){
    n=read();
    D=read();
    ll ans=0;
    for(int i=1;i<=n;i++)a[i]=read(),f[i]=g[i]=1;
    for(int i=1,j=1;i<=n;i++){
        while(j<n&&a[i]+D>=a[j+1])j++;
        nxt[i]=j;
        //cout<<i<<" "<<j<<endl;
    }
    for(int i=n,j=n;i;i--){
        while(j>1&&a[i]-D<=a[j-1])j--;
        pre[i]=j;
    }
    for(int i=1;i<=n;i++){
        if(nxt[i]!=i){
            int j=nxt[i];
            if(pre[j]==i)f[j]+=f[i];
            else f[j]++;
        }
    }

    for(int i=n;i;i--){
        if(pre[i]!=i){
            int j=pre[i];
            if(nxt[j]==i)g[j]+=g[i];
            else g[j]++;
        }
    }
    //for(int i=1;i<=n;i++)cout<<pre[i]<<" "<<nxt[i]<<" "<<f[i]<<" "<<g[i]<<endl;

    for(int i=1;i<=n;i++){
        if(nxt[i]-i>1){
            int j=nxt[i];
            int k=nxt[j];
            int l=nxt[j-1];
            int p=nxt[j-2];
            ll la=(pre[j-1]==i?f[i]:1);
            if(j==k||l==j||p==k)continue;
            ans+=(l-nxt[j-2])*la;
            if(k!=l)continue;
            ans=ans-la+la*g[k];
        }
    }

    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll t;
    t=read();;
    t=read(); //echo form
    while(t--)solve();
    return 0;
}
