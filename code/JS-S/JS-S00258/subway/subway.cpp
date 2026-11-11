#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MAXM=1005,MAXN=1005;
struct station{
    ll v;//cost to outside
    vector<ll> next;
    ll t[MAXM];//cost to station i
} a[MAXM];

ll w[MAXM];//cost at begin & end
ll c,n,m,d,q;

queue<ll> target;
ll cost[MAXM];

ll bfs(ll x,ll y){
    for(int i=1;i<=m;i++){
        cost[i]=1e18;
    }
    cost[x]=a[x].v;
    target.push(x);
    while(!target.empty()){
        for(int i=target.size()-1;i>=0;i--){
            ll op=target.back();
            for(int j=0;j<a[op].next.size();j++){
                if((cost[a[op].next[j]])>(cost[op]+a[a[op].next[j]].t[op]+a[op].t[a[op].next[j]])){
                    cost[a[op].next[j]]=(cost[op]+a[a[op].next[j]].t[op]+a[op].t[a[op].next[j]]);
                    target.push(a[op].next[j]);
                }
            }
            target.pop();
        }
    }
    return cost[y]+a[y].v;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i].v;
    }

    ll k,t[MAXN],id[MAXM];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>id[j];
            cin>>t[j];
        }

        a[id[1]].t[id[2]]=t[1];
        a[id[1]].next.push_back(id[2]);
        a[id[k]].t[id[k-1]]=t[k];
        a[id[k]].next.push_back(id[k-1]);
        for(int j=2;j<=k-1;j++){
            a[id[j]].t[id[j+1]]=t[j];
            a[id[j]].next.push_back(id[j+1]);
            a[id[j]].t[id[j-1]]=t[j];
            a[id[j]].next.push_back(id[j-1]);
        }
    }

    for(int i=1;i<=m;i++){
            cout<<i<<':';
        for(int j=0;j<a[i].next.size();j++){
            cout<<a[i].t[a[i].next[j]]<<','<<a[i].next[j]<<' ';
        }
        cout<<endl;
    }


    ll x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<bfs(x,y)<<' ';
    }

	return 0;
}
