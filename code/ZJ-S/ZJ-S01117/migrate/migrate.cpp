#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x7f7f7f7f7f7f7f7f;
int c,T;
int n,d,ans;
int a[2000050],dis[5050],tiao[5010],rd[5050][5050]; 
vector<pair<int,int>>g[5050];
bool vis[5050];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void djt(int st){
	memset(vis,0,sizeof vis);
	memset(dis,0x7f,sizeof dis);
	memset(tiao,0,sizeof tiao);
	q.push({0,st});
	dis[st]=0;
	tiao[st]=1;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			int nx=g[x][i].second;
			int cost=g[x][i].first;
			if(dis[nx]>dis[x]+cost){
				dis[nx]=dis[x]+cost;
				tiao[nx]=tiao[x];
				q.push({dis[nx],nx});
			}
			else if(dis[nx]==dis[x]+cost){
				tiao[nx]+=tiao[x];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	if(c<=10){
		while(T--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				g[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d) break;
					g[i].push_back({1,j});
				}
			}
			for(int i=1;i<=n;i++){
				djt(i);
				for(int j=i;j<=n;j++){
				//	cout<<tiao[j]<<" ";
					if(tiao[j]==2) ans++;
				}
				//cout<<"\n";
			}
			cout<<ans<<"\n";
		}
	}
	else{
		while(T--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[3]-a[1]>d) cout<<0<<"\n";
			else{
				cout<<n-3<<"\n";
			}
		}
	}
}
