#include <bits/stdc++.h>
#define INF (0x7FFFFFFF)
#define LL_INF (4e18)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5e3+10;
vector<int> gragh[N];
int dist[N][N],cnt[N][N],c,n; 
ll x[N],d;
bool vis[N]; 
queue<pii> q; 
void bfs(int s){
	for (int i=1;i<=n;i++){
		dist[s][i]=INF,cnt[s][i]=0,vis[i]=false;
	}
	while (!q.empty()){
		q.pop();
	}
	dist[s][s]=0,cnt[s][s]=1,q.push({0,s});
	while (!q.empty()){
		int u=q.front().second,dis=q.front().first;
		q.pop();
		if (vis[u]){
			continue;
		}
		vis[u]=true;
		for (auto v:gragh[u]){
			if (dis+1<dist[s][v]){
				dist[s][v]=dis+1,cnt[s][v]=cnt[s][u],q.push({dis+1,v});
			}
			else if (dis+1==dist[s][v]){
				cnt[s][v]+=cnt[s][u];
			}
		}
	} 
} 
void solve(){
	cin>>n>>d;
	for (int i=1;i<=n;i++){
		cin>>x[i],gragh[i].clear(); 
	}
	sort(x+1,x+1+n);
	if (n==1){
		cout<<0<<endl;
		return; 
	}
	if (c<=10){
		for (int i=1;i<=n;i++){
			for (int j=i-1;(j>=1)&&(x[i]-x[j]<=d);j--){
				gragh[i].push_back(j);
			}
			for (int j=i+1;(j<=n)&&(x[j]-x[i]<=d);j++){
				gragh[i].push_back(j);
			}
		}
		int ans=0; 
		for (int i=1;i<=n;i++){
			bfs(i);
			for (int j=i+1;j<=n;j++){
				ans+=(cnt[i][j]==2); 
			} 
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0); 
	int T;
	cin>>c>>T;
	while (T--){
		solve();
	}
	return 0;
}

