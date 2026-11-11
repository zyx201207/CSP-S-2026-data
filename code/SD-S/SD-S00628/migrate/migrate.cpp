#include<bits/stdc++.h>
using namespace std;

#define F(i,s,e) for(int i=s;i<=e;i++)
const int N = 2e6+10,M = 5e3+10;
using ll = long long;
const ll inf = 2e18; 
ll x[N];
ll dis[M][M],cnt[M][M],vis[M];
vector<int>g[M]; 
void bfs(int s){
	memset(dis[s],0x3f,sizeof dis[s]);
	memset(cnt[s],0,sizeof cnt[s]);
	memset(vis,0,sizeof vis);
	dis[s][s]=0;
	queue<int>q;
	for(int u:g[s]) cnt[s][u]=dis[s][u]=1,q.push(u);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();vis[u]=0;
		for(int v:g[u]) {
			if(dis[s][v]>dis[s][u]+1) {dis[s][v]=dis[s][u]+1,cnt[s][v]=cnt[s][u];if(!vis[v]) q.push(v),vis[v]=1;}
			else if(dis[s][v]==dis[s][u]+1) cnt[s][v]+=cnt[s][u];
			if(cnt[s][v]>5) cnt[s][v]=5;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;cin>>c>>t;
	if(c<=10){
		while(t--){
			ll n,d,ans=0;cin>>n>>d;
			F(i,1,n) cin>>x[i],g[i].clear();
			F(i,1,n) F(j,i+1,n) if(x[j]-x[i]<=d) g[i].push_back(j);
			F(i,1,n) bfs(i);
//			cout<<g[2][1];
//			cout<<dis[1][4];
			F(i,1,n) F(j,i+1,n) if(cnt[i][j]==2) ans++;
			cout<<ans<<'\n';
		}
		
	}if(c==11||c==12){
		while(t--){
			ll n,d,ans=0;cin>>n>>d;
			F(i,1,n) cin>>x[i];
			ll now = x[2]-x[1];
			ll cnt=d/now;
			if(cnt==1||cnt==0) cout<<"0\n";
			else{
				F(i,1,n){
					ll l=i,r=i+cnt*2-1;
					if(r>n) break;
					ans+=1;
				}
				cout<<ans<<'\n';
			}
		}
	}	
 	return 0;
} 

/*
11 1
10 22
0 7 14 21 28 35 42 49 56 63

*/
