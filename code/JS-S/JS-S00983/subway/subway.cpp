#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const int MN=505;
const int MM=5e5+5;
ll c,n,m,d,q;
ll s,ta1,tt1,ta2,tt2,x,y,ans;
ll w[MM];
vector<int> a[MN];
vector<pll> t[MN];
vector<pll> g[MN];
vector<ll> dis[MN];

void dij(int s){
    priority_queue<pll,vector<pll>,greater<pll> > q;

}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>s>>ta1>>tt1>>ta2>>tt2;
        g[ta1].push_back({ta2,tt1+tt2});
        g[ta2].push_back({ta1,tt1+tt2});
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        if(x>y) swap(x,y);
        ans=w[x]+w[y];
        ans+=tt1+tt2;
        cout<<ans<<endl;
    }
    return 0;
}
