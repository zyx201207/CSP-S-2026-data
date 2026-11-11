#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
using namespace std;
const int inf=1e18;
const int maxn=2000005;
vector<int> a[maxn];
int vis[maxn];
int dis[maxn];
int f[maxn];
int p[maxn];
int C,_;
int n,m;
int ans;
void bfs(int sx){
	queue<int> que;
	que.push(sx);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		if(vis[x]) continue;
		vis[x]=1;
		int l=a[x].size();
		for(int i=0;i<l;i++){
			int nx=a[x][i];
			if(vis[nx]) continue;
			if(dis[x]+1<dis[nx]){
				dis[nx]=dis[x]+1;
				f[nx]=f[x];
				que.push(nx);
			}
			else if(dis[x]+1==dis[nx]){
				f[nx]+=f[x];
				que.push(nx);
			}
		}
	}
}
void solve(){
	if(C<=10){
		for(int i=1;i<=n;i++) a[i].clear();
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(p[j]-p[i]<=m) a[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dis[j]=n;
				vis[j]=0;
				f[j]=0;
			}
			dis[i]=0;
			f[i]=1;
			bfs(i);
			for(int j=i+1;j<=n;j++) if(f[j]==2) ans++;
		}
		cout<<ans<<"\n";
		return;
	}
	if(C==11||C==12){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>p[i];
		int d=m/(p[2]-p[1]);
		if(d!=2) cout<<"0\n";
		else{
			for(int i=1;i<=n;i++){
				if((n-i)&1) ans+=n-i-1;
				else ans+=n-i;
			}
			cout<<ans<<"\n";
		}
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>C>>_;
	while(_--) solve();
	return 0;
}
