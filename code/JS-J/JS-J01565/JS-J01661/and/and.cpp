#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
bool vis[200005];
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9'){
        x=x*10+(ch-48);
        ch=getchar();
    }
    return x*f;
}
bool cmp(ll a,ll b){
    return a>b;
}
ll maxx=-INT_MAX;
void dfs(ll id,ll step,ll sum){
    if(step==m){
        maxx=max(maxx,sum);
        return ;
    }
    for(int i = 1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(i,step+1,sum&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1;i<=n;i++){
        vis[i]=1;
        dfs(i,1,a[i]);
        vis[i]=0;
    }
    cout<<maxx;
    return 0;
}
