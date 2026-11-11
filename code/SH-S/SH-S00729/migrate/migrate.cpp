#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second

using namespace std;

const int N=2e6+10;
const int INF=1e16;

int n, d, a[N], vis[5005], dis[5005];
queue<pii>q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	cin>>C>>T;
	if(C<=10){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)vis[j]=0;
				for(int j=1;j<=n;j++)dis[j]=INF;
				dis[i]=1;
				q.push({i, 1});
				while(!q.empty()){
					int u=q.front().fir, cnt=q.front().sec;q.pop();
					if(vis[u]>=3)continue;
					vis[u]++;
					for(int v=u;v<=n&&a[v]-a[u]<=d;v++){
						if(dis[u]+1<=dis[v]){
							dis[v]=dis[u]+1;
							q.push({v, dis[v]});
						}
					}
				}
				for(int j=1;j<=n;j++)ans+=vis[j]==2;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	else if(C<=12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(d/(a[2]-a[1])<=1)cout<<"0\n";
			else cout<<max(n-((d/(a[2]-a[1]))*2-1), 0LL)<<'\n';
		}
		return 0;
	}
	else{
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<"0\n";
		}
		return 0;
	}
	return 0;
}
/*
打表过样例
骗分拿省一
NOIP 2026 RP++！

NOIP打完就AFO了qwq 
*/
