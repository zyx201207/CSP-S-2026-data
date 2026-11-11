#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int N=1000+10,M=505,INF=1e18+10;
int n,k;
int c,T;
vector<int>g[N];
int f[N];
int h[N];
int t[N];
int cnt;
int ans;
void dfs(int x,int fa,int o){
	f[x]=min(f[x],o);
	int kk=o;
	if(t[x])kk=0;
	for(auto e:g[x]){
		if(e!=fa){
			dfs(e,x,kk+1);
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=n;
		for(int i=(1<<n)-1;i>=0;i--){
			if(__builtin_popcount(i)>k)continue;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					t[j+1]=1;
					f[j+1]=0;
				}
				else t[j+1]=0,f[j+1]=INF;
			}
			cnt=0;
			for(int j=1;j<=n;j++){
				if(t[j])dfs(j,0,0);
			}
			for(int j=1;j<=n;j++){
				cnt=max(cnt,f[j]);
			}
			if(cnt<ans)ans=cnt;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
