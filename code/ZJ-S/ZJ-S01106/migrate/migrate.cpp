#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,ans,n,d,i,j,fx,dis[2000010],vis[2000010],a[2000010];
priority_queue<int,vector<int>,greater<int> >q;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	cin>>T;
	cin>>T;//c没有用，用T覆盖
	while(T--) {
		ans=0;
		cin>>n>>d;
		for(i=1; i<=n; i++)cin>>a[i];
		memset(dis,127,sizeof(dis));
		memset(vis,0,sizeof(vis));
		q.push(1),dis[1]=0,vis[1]=1;
		while(q.size()) {
			fx=q.top();
			q.pop();
			for(i=1; i<=n; i++)
				if(fx!=i&&!vis[i]&&abs(a[i]-a[fx])<=d) {
					q.push(i),vis[i]=1;
					if(dis[fx]+1<=dis[i]) {
						if(dis[fx]+1==dis[i])ans++;
						dis[i]=dis[fx]+1;
					}
				}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
