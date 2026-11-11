#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[2000200];
vector<int> g[2000200];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) {
		int ans = 0;
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
		for(int i = 1;i <= n;i++) g[i].clear();
		if(n<=5000) {
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					if(i!=j&&abs(a[i]-a[j])<=d) {
//						cout << "Edge " << i << "->" << j << endl;
						g[i].push_back(j);
					}
				}
			}
			for(int i = 1;i <= n;i++) {
				queue<int> q;
				bool cnt[500]={false};
				int dis[500];
				int num[500]={0};
				for(int j = 1;j <= n;j++) dis[j]=1e18;
				dis[i]=0;
				num[i]=1;
				q.push(i);
				while(!q.empty()) {
					int now = q.front();
					q.pop();
					if(cnt[now]) continue;
					cnt[now]=1;
					for(int k = 0;k < g[now].size();k++) {
						int v = g[now][k];
						if(dis[now]+1<dis[v]) {
							dis[v]=dis[now]+1;
							num[v]=num[now];
							q.push(v);
						}else if(dis[now]+1==dis[v]) num[v]+=num[now];
					}
				}
				for(int j = i+1;j <= n;j++) {
					if(num[j]==2) {
//						cout << "Find " << i << " " << j << endl;
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}else {
			int D = d/(a[2]-a[1]);
			if(D==0||D==1) {
				printf("0\n");
				continue;
			}
			int ans = 0;
			for(int i = 1;i <= n;i++) {
				if(i+2*D-1<=n) ans++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
1 1
10 3327
-10000 -6673 -3346 -1128 1090 2199 3308 4417 6635 9962
*/
