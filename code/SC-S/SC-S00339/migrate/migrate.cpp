#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int a[2000010];
int dist[2000010];
int num[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<pii>G[n+1];
		for(int i = 1;i<=n;i++){
			cin >> a[i];
			for(int j = 1;j<i;j++){
				if(a[i]-a[j]<=d){
					G[i].push_back({j,1});
					G[j].push_back({i,1});
				}
			}
		}
		int ans=0;
		for(int s = 1;s<n;s++){
			memset(dist,-1,sizeof(dist));
			memset(num,0,sizeof(num));
			queue<int>q;
			q.push(s);
			dist[s]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(pii mbpsz:G[u]){
					int v=mbpsz.first;
					int w=mbpsz.second;
					if(dist[v]==-1) dist[v]=dist[u]+w,num[v]++;
					else if(dist[u]+w<dist[v]) dist[v]=dist[u]+w,num[v]=1;
					else if(dist[u]+w==dist[v]) num[v]++;
					else continue;
					q.push(v);
				}
			}
			for(int e = s+1;e<=n;e++){
//				cout << '-' << s << ' ' << e << ':' << num[e] << '\n';
				if(num[e]==2){
					ans++;
				}
			}
		}
		cout << ans;
		cout << '\n';
	}
	return 0;
}