#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c,d,q,w[500005],k[500005],x,y,s=100000009,a[505][1005],t[505][1005];
bool bj[500005];
struct V{
    ll ss,tt[1005],sn[1005];
}f[1005];
void dfs(ll st,ll ed,ll ans,ll cme){
    if(ans>=s){
        return;
    }
    if(st==ed){
        s=min(s,ans);
        return;
    }
    bj[st]=1;
    for(int i=1;i<=f[st].ss;i++){
        ans+=f[st].tt[i];
        ll xl=f[st].sn[i];
        if(xl==cme){
            ans-=f[st].tt[i];continue;
        }
        for(int j=1;j<=k[xl];j++){
            ll nw=a[xl][j];
            if(nw==st||(f[nw].ss==0&&nw!=ed)||bj[nw]==1)continue;
            else{
                dfs(nw,ed,ans+t[xl][j],xl);
            }
        }
        ans-=f[st].tt[i];
    }
    bj[st]=0;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            f[a[i][j]].ss++;
            f[a[i][j]].sn[f[a[i][j]].ss]=i;
            f[a[i][j]].tt[f[a[i][j]].ss]=t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        s=1000000000;
        cin>>x>>y;
        dfs(x,y,0,n+1);
        s+=w[x]+w[y];
        cout<<s<<'\n';
    }
    return 0;
}
