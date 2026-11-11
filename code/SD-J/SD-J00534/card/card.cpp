#include <bits/stdc++.h>

#define PII pair <int,int>
#define fi first
#define se second
#define all(u) (u).begin(),(u).end()
#define lb lower_bound
#define ub upper_bound
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define ll long long
#define N 1000005

using namespace std;
int n,m;
int a[N],ans[N];
bool vis[N],now[N];
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
//	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	for(int i = 1;i <= n;i ++) {
		memset(vis,0,sizeof(vis));
		for(int j = i;j <= n;j ++) {
			if(!vis[a[j]] && now[a[j]]) {
				for(int k = now[a[j]] + 1;k < j;k ++) vis[a[k]] = 1;
			}
			else if(!vis[a[j]]) now[a[j]] = 1; 
		}
		for(int j = 1;j <= m;j ++) {
			ans[j] += !vis[j];
//			cout<<vis[j];
		}
//		cout<<"\n";
	}
	for(int i = 1;i <= m;i ++) {
		cout<<ans[i]<<" ";
	}cout<<"\n";
	return 0;
}

