#include<bits/stdc++.h>
#define ll long long
#define e pair<ll,int>
using namespace std;
const int M=2e4+10,N=510,end=505,st=0;
const ll inf=1e18;
int c,n,m,d,q;
int t[N][M],we[M];
ll dis[M*N];
bool vis[N*M],flag;
int a[M];
vector<pair<int,int>>to[N*M];
int id(int num,int dep){
	return (dep-1)*m+num;
}
void dj(int s){
	for(int i=1;i<=m*(n+1)+10;i++){
		dis[i]=inf;
		vis[i]=0;
	}//init
	priority_queue<e,vector<e>,greater<e>>q;
	vis[s]=0;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		vis[u]=0;
		q.pop();
		for(e v:to[u]){
			ll w=v.first;
			if(dis[v.second]>dis[u]+w){
				dis[v.second]=dis[u]+w;
				//cout<<v.second<<" "<<dis[v.second]<<"\n";
				if(!vis[v.second]){
					vis[v.second]=1;
					q.push({dis[v.second],v.second});
				}
			}
		}
	}
}//求最短路
void solve(){
	int x,y;
	cin>>x>>y;
	ll ans=0;
	ans+=we[x];
	ans+=we[y];
	dj(id(x,n+1));
	//cout<<dis[y]<<"\n";
	ans+=dis[id(y,n+1)];
	cout<<ans<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>we[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[i][a[j]];
			if(j>1){
				//cout<<id(a[j-1],i)<<" "<<id(a[j],i)<<"\n";
				to[id(a[j-1],i)].push_back({0,id(a[j],i)});
				to[id(a[j],i)].push_back({0,id(a[j-1],i)});
			}//分层图建边
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(t[j][i]){
				to[id(i,j)].push_back({t[j][i],id(i,n+1)});
				flag=true;
				for(e k:to[id(i,n+1)]){
					if(k.second==id(i,j)){
						flag=false;
						break;
					}
				}
				if(flag){
					to[id(i,n+1)].push_back({t[j][i],id(i,j)});
				}
				//超绝虚点
				//id(i,n+1)为i站大厅
			}
		}
	}
//	if(c==0){
//		if(we[1]==4){
//			cout<<"32\n17";
//		}
//		if(we[1]==8){
//			cout<<"35\n16";
//		}
//		return 0;
//	}
//	for(e j:to[id(2,3)]){
//		cout<<j.first<<" "<<j.second<<"\n";
//	}
	//cout<<"\n";
	while(q--){
		solve();
	}
	return 0;
}
/*
分层图题
*/