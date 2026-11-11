#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
const int maxnn=5e3+7;
const int maxn=2e6+7;
const int inf=1e9+7;
int pos[maxn];
vector<int> edge[maxnn];
int dis[maxnn];
bool vis[maxnn];
int dp[maxnn];
int dij(int x) {
	for(int i=1; i<=n; i++)
		dis[i]=inf,vis[i]=0;
	queue<int> que;
	que.push(x);
	dis[x]=0;
	while(que.size()) {
		int u=que.front();
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:edge[u]) {
			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				que.push(v);
			}
		}
	}
	for(int i=1; i<=n; i++) vis[i]=dp[i]=0;
	que.push(x);
	dp[x]=1;
	while(que.size()) {
		int u=que.front();
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:edge[u]) {
			if(dis[v]==dis[u]+1) {
				dp[v]+=dp[u];
				que.push(v);
			}
		}
	}
	int cnt=0;
	for(int i=x+1; i<=n; i++)
		if(dp[i]==2) cnt++;
	return cnt;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)
			cin>>pos[i];
		if(c<=10) {
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					if(pos[j]-pos[i]>d) break;
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
			int ans=0;
			for(int i=1; i<=n; i++)
				ans+=dij(i);
			cout<<ans<<"\n";
			for(int i=1; i<=n; i++)
				edge[i].clear();
		} else if(c==11 || c==12) {
			if((d/(pos[2]-pos[1]))<2) cout<<"0\n";
			else {
				int len=(d/(pos[2]-pos[1]))*2-1;
				if(n>=len) cout<<n-len<<"\n";
				else cout<<"0\n";
			}
		}else if(c==13 || c==14){
			int mid=n/2;
			for(int i=max(1ll,mid-5);i<=min(n,mid+5);i++){
				if(pos[i]-pos[1]<=d && pos[n]-pos[i]<=d){
					mid=i;
					break;
				}
			}
			int l=n;
			int cnt=0;
			for(int i=mid-1;i>=1;i--){
				while(l>mid && pos[l]-pos[i]>d) l--;
				if(l>=mid && pos[l]-pos[i]<=d){
					if(l-i==2)
						cnt+=n-l+1;
				}
			}
			cout<<cnt<<"\n";
		}

	}
	return 0;
}
