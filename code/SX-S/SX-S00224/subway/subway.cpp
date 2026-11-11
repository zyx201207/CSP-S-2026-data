#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,myr,x,y,aa;
ll w[M],a[N][N],dis[N][N],ans;
struct T{
	int to,v;
};
vector<T>t[M];
struct Q{
	int i;
	ll dis;
	bool operator<(const Q& other)const&{
		return dis>other.dis;
	}
};
priority_queue<Q> q;
void dijikstra(int x){
	q.push({x,0});
	int u;
	while(!q.empty()){
		u=q.top().i;
		if(q.top().dis!=dis[x][u]){
			q.pop();
			continue;
		}
		q.pop();
		for(int v=1;v<=n;v++){
			if(dis[x][v]>dis[x][u]+a[u][v]){
				dis[x][v]=dis[x][u]+a[u][v];
				q.push({v,dis[x][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>myr;
	memset(a,0x3f,sizeof a);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		a[i][i]=dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>aa>>y;
			t[aa].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int u=0;u<t[i].size();u++){
			for(int v=0;v<t[i].size();v++){
				a[t[i][u].to][t[i][v].to]=min(a[t[i][u].to][t[i][v].to],(ll)(t[i][u].v+t[i][v].v));
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijikstra(i);
	}
	while(myr--){
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int u=0;u<t[x].size();u++){
			for(int v=0;v<t[y].size();v++){
				ans=min(ans,(ll)t[x][u].v+(ll)t[y][v].v+dis[t[x][u].to][t[y][v].to]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
