#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N =5e5;
ll c=0,n=0,m=0,d=0,q=0;
ll w[N+5],v[N+5][505];
vector<ll> tme[505],a[505],e[N+5];

ll djk(ll st,ll ed){
    ll dep[N]={};
    int vis[N]={};
    priority_queue<pair<ll,ll>>que;
    que.push(make_pair(0,st));
    vis[st]=-1;
    while(!que.empty()){
        ll dp=que.top().first;
        ll t=que.top().second;
        que.pop();
        if(t==ed){
            return -dp;
        }
        for(ll i=0;i<e[t].size();i++){
            ll k=e[t][i];
            ll dpe=dp;
            if(vis[t]!=k){
                dpe-=v[t][k];
            }
            for(ll j=0;j<a[k].size();j++){
                if(a[k][j]==t||dep[a[k][j]]<=dpe-tme[k][j]){
                    continue;
                }
                dep[a[k][j]]=dpe-tme[k][j];
                vis[a[k][j]]=k;
                que.push(make_pair(dpe-tme[k][j],a[k][j]));
            }
        }
    }
    return -1;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        ll k=0;
        cin>>k;
        for(ll j=0;j<k;j++){
            a[i].push_back(0);
            tme[i].push_back(0);
            cin>>a[i][j]>>tme[i][j];
            e[a[i][j]].push_back(i);
            v[a[i][j]][i]=tme[i][j];
        }
    }
    while(q--){
        ll l=0,r=0;
        cin>>l>>r;
        cout<<djk(l,r)+w[l]+w[r]<<"\n";
    }
    return 0;
}
