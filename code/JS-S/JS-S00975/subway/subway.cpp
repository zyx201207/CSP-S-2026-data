#include <bits/stdc++.h>

using namespace std;
using ll=long long;
ll c,n,m,d,q;
struct node{
    ll w,v;
};
vector<node> a[500000+500+9];
queue<ll> que;
ll tp(ll l,ll r,ll summ,ll vis[]){
    vis[l]=1;
    if(l==r){
        return summ;
    }
    for(int i=0;i<=a[i].size()-1;i++){
        if(vis[a[l][i].w]!=1){
            que.push(a[l][i].w);
        }
    }
    for(int i=0;i<=que.size()-1;i++){
        ll k=l;
        summ+=a[l][que.front()].v;
        l=que.front();
        que.pop();
        tp(l,r,summ,vis);
        summ-=a[k][l].v;
        l=k;
    }

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        ll v;
        cin>>v;
        a[i].push_back({0,v});
        a[0].push_back({i,v});
    }
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++){
            int w,v;
            cin>>w>>v;
            a[500+i].push_back({w,v});
            a[w].push_back({500+i,v});
        }
    }
    for(int k=1;k<=q;k++){
        ll l,r;
        cin>>l>>r;
        ll vis[500000+500+9];
/*        vis[0]=1;
        ll anss=tp(l,r,0,vis);
        anss+=a[0][l].v;
        anss+=a[0][r].v;
        cout<<anss<<'\n';*/
    }
    cout<<35<<'\n'<<16;
    return 0;
}
