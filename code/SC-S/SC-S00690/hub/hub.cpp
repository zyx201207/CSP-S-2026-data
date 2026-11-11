#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,minn=2e18;
vector<ll>a[1000005];
ll fa[100005],dep[100005],pre[100005],xans;
ll find(ll s){
    if(fa[s]==s)return s;
    fa[s]=find(fa[s]);
    return fa[s];
}
ll ju(ll x,ll y){
    if(dep[x]<dep[y])swap(x,y);
    ll jsq=0;
    while(dep[x]>dep[y])jsq++,x=pre[x];
    while(x!=y){
        jsq+=2;
        x=pre[x],y=pre[y];
    }
    return jsq;
}
void work(ll s){
    ll jsq=0;
    for(int i=1;i<=n;i++){
        if((s>>(i-1))&1)jsq++;
    }
    if(jsq!=k)return;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
        if(((s>>(i-1))&1)==0)continue;
        for(auto v:a[i]){
            if(((s>>(v-1))&1)&&((s>>(i-1))&1)){
                ll fu=find(i),fv=find(v);
                if(fu!=fv)fa[fu]=fv;
            }
        }
    }
    jsq=0;
    for(int i=1;i<=n;i++){
        if(((s>>(i-1))&1)&&fa[i]==i)jsq++;
    }
    if(jsq>2)return;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if((s>>(i-1))&1)continue;
        ll minn=2e18;
        for(int j=1;j<=n;j++){
            if(((s>>(j-1))&1)==0)continue;
            minn=min(minn,ju(i,j));
        }
        ans=max(ans,minn);
    }
    xans=min(xans,ans);
}
void dfs(ll x,ll from){
    for(auto v:a[x]){
        if(v==from)continue;
        pre[v]=x;
        dep[v]=dep[x]+1;
        dfs(v,x);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)a[i].clear();
        for(int i=1;i<=n-1;i++){
            ll u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1,0);
        ll S=(1<<n)-1;
        xans=2e18;
        for(int s=0;s<=S;s++){
            work(s);
        }
        cout<<xans<<'\n';
    }
    return 0;
}