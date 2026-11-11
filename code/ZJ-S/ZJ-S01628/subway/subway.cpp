#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mpx=5e5+5;
const int mcx=505;
int c,n,m,d,q,w[mpx];
struct xu{
	int v,w;
	bool operator <(const xu &B)const{return w>B.w;}
}a[mpx];
vector<xu> e[mpx];
int dis[mpx];
bool v[mpx];
void Dij(int st){
	memset(dis,0x3f,sizeof dis);
	memset(v,0,sizeof v);
	priority_queue<xu> q;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		xu t=q.top();q.pop();
		if(v[t.v])continue;
		v[t.v]=1;
		for(xu u:e[t.v]){
			if(dis[u.v]>dis[t.v]+u.w){
				dis[u.v]=dis[t.v]+u.w;
				q.push({u.v,dis[u.v]});
			}
		}
	}
}
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j].v>>a[j].w;
		for(int l=1;l<=k;l++){
			for(int r=1;r<=k;r++){
				if(l==r)continue;
				int w=a[l].w+a[r].w;
				e[a[l].v].push_back({a[r].v,w});
				e[a[r].v].push_back({a[l].v,w});
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		Dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
