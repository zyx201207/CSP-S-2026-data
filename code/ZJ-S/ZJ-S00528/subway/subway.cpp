#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct N{
	ll v,w;
	bool operator <(const N tmp)const{
		return w>tmp.w;
	}
};
ll w[500005],a[500005],t[500005],dis[1000005],res[100005],h[505][505];
vector<N> g[1000005];
void Dij(int s){
	priority_queue<N> q;
	memset(dis,0x7f,sizeof(dis));
	dis[s] = 0;
	q.push(N{s,0});
	while(!q.empty()){
		N x=q.top();
		q.pop();
		if(dis[x.v]!=x.w){
			continue;
		}
		for(N e:g[x.v]){
			if(dis[e.v]>dis[x.v]+e.w){
				dis[e.v] = dis[x.v]+e.w;
				q.push(N{e.v,dis[e.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c,n,m,d,q,cnt;
	cin>>c>>n>>m>>d>>q;
	cnt = m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			h[i][j] = 2e15;
		}
		h[i][i] = 0;
		int k;
		cin>>k;
		cnt++;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			g[a[j]].push_back(N{cnt,t[j]});
			g[cnt].push_back(N{a[j],t[j]});
		}
	}
	for(int i=1;i<=m;i++){
		int k=g[i].size();
		for(int u=0;u<k;u++){
			for(int v=u+1;v<k;v++){
				h[g[i][u].v-m][g[i][v].v-m] = h[g[i][v].v-m][g[i][u].v-m] = min(h[g[i][u].v-m][g[i][v].v-m],g[i][u].w+g[i][v].w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				h[i][j] = min(h[i][j],h[i][k]+h[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll s,t,res=2e15;
		cin>>s>>t;
		for(N u:g[s]){
			for(N v:g[t]){
				res = min(res,h[u.v-m][v.v-m]+u.w+v.w);
			}
		}
		cout<<res+w[s]+w[t]<<'\n';
	}
	return 0;
}
