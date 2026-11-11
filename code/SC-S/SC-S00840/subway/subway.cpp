#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=5e5+10;
const ll INF=1e18;
int ceshi,n,m,dmax,q;
ll wout[M];
ll dis[N][N];
struct node{
	int id;
	ll t;
};
vector<node> sta[M];
int k[N];
vector<int> a[N];
vector<ll> t[N];
void zuiduanlu(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>ceshi>>n>>m>>dmax>>q;
	for(int i=1;i<=m;i++) cin>>wout[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ta,tt;
			cin>>ta>>tt;
			a[i].push_back(ta);
			t[i].push_back(tt);
			sta[ta].push_back((node){i,tt});
		}
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(node &t1:sta[i]){
			for(node &t2:sta[i]){
				int id1=t1.id,id2=t2.id;
				dis[id1][id2]=min(dis[id1][id2],t1.t+t2.t);
				dis[id2][id1]=min(dis[id2][id1],t1.t+t2.t);
			}
		}
	}
	zuiduanlu();
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(node &t1:sta[x]){
			for(node &t2:sta[y]){
				int id1=t1.id,id2=t2.id;
				ans=min(ans,dis[id1][id2]+t1.t+t2.t);
			}
		}
		ans+=wout[x]+wout[y];
		cout<<ans<<"\n";
	}
	return 0;
}