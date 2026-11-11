#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e3 + 10;
int n;
ll x[N],d;
int dis[N][N],cnt[N][N];
void bfs(int s){
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = u + 1;i <= n;++i){
			if(x[i] - x[u] > d)break;
			if(!dis[s][i]){
				dis[s][i] = dis[s][u] + 1;
//				cerr<<dis[s][i]<<" ";
				cnt[s][i]++;
				q.push(i);
			}else if(dis[s][i] == dis[s][u] + 1)cnt[s][i]++;
		}
	}
//	cerr<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int __,_;
	cin>>__>>_;
	while(_--){
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		cin>>n>>d;
		for(int i = 1;i <= n;++i)cin>>x[i];
		if(n > 5000){
			ll dt = x[2] - x[1];
			ll ct = d / dt;
			ll ans = 0;
			if(ct > 2)cout<<0<<"\n";
			else if(ct == 2){
				cout<<(n - ct + 1) * (n - ct) / 2<<"\n";
			}else if(ct == 1)cout<<(n - 1) * n / 2<<"\n";
			continue;
		}
		for(int i = 1;i <= n;++i)bfs(i);
		int ans = 0;
		for(int i = 1;i < n;++i){
			for(int j = i + 1;j <= n;++j){
//				cout<<cnt[i][j]<<" ";
				if(cnt[i][j] == 2){
					ans++;
				}
			}
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
}
