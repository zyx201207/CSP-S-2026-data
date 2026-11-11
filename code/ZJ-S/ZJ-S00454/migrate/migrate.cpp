#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e3+10;
int n,d,ans;
int a[N];
int dis[N],cnt[N];
vector<int> e[N];
void bfs(int x){
	for(int i=1;i<=n;i++) dis[i]=0,cnt[i]=1;
	dis[x]=1;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int& v:e[u]){
			if(dis[v]){
				if(dis[v]==dis[u]+1){
					if(cnt[v]==2) ans--;
					cnt[v]+=cnt[u];
					if(cnt[v]==2) ans++;
				}
				continue;
			}
			dis[v]=dis[u]+1;
			cnt[v]=cnt[u];
			if(cnt[v]==2) ans++;
			q.push({v});
		}
	}
	return;
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],e[i].clear();
	int j=1;
	for(int i=1;i<=n;i++){
		for(int k=i+1;k<=j;k++) e[i].push_back(k);
		while(j<n&&a[j+1]-a[i]<=d) j++,e[i].push_back(j);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _,__;
	cin>>__>>_;
	while(_--) solve();
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}
