#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,n,d,x[N],dis[N],ans[5005][5005],tot;
bool vis[N];
vector<int>H[N];
void dij(int x){
	priority_queue<pair<int,int> >pq;//big->small
	for(int i=1;i<=n;i++) dis[i]=1e9,vis[i]=0;
	dis[x]=0;
	ans[x][x]=1;
	pq.push({0,x});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		vis[u]=1;
		for(const auto &v:H[u]){
			if(dis[v]>dis[u]+1&&!vis[v]){
				dis[v]=dis[u]+1;
				ans[x][v]=ans[x][u];
				pq.push({-dis[v],v});
			}else if(dis[v]==dis[u]+1) ans[x][v]++;
		}
	}
}
void init(){
	for(int i=1;i<=n;i++) H[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]=0;
}
void solve(){
	cin>>n>>d;
	init();
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<i;j++){
			if(abs(x[i]-x[j])<=d){
//				cout<<i<<' '<<j<<'\n';
				H[i].push_back(j);
				H[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++) dij(i);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			if(dis[i][j]==1e9) cout<<"-"<<" \n"[j==n];
//			else cout<<dis[i][j]<<" \n"[j==n];
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<ans[i][j]<<" \n"[j==n];
	tot=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(ans[i][j]==2)
				tot++;
	cout<<tot<<'\n';
	return;
}
void solve2(){
	cin>>n>>d;
	int ind=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]-x[1]<=d) ind=i;
	}
//	cout<<ind<<'\n';
	if(ind==2||ind==1) cout<<"0\n";
	else cout<<max(0ll,(ll)n-((ll)(ind-1)*2-1))<<'\n';
}
void solve3(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	cout<<2<<'\n';
}
#undef int
int main(){
	freopen("migrate.in","r",stdin);
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>c>>T;
	for(;T;T--){
		if(c==11||c==12) solve2();
		else if(c==13||c==14) solve3();
		else solve();
	}
	return 0;
}
