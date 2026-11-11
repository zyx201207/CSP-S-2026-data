#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;

const int maxn = 5e5 + 15,inf = 1e9;
ll n,d,a[maxn],dis[maxn],cnt[maxn];
vector<int> mp[maxn];
void clean(ll n){
	for(int i = 1;i <= n;i++){
		mp[i].clear();
	}
}
void bfs(int s,ll d[],ll cnt[],ll &ans){
	queue<int> q;
	q.push(s);
	for(int i = 0;i <= n;i++) d[i] = inf,cnt[i] = 0;
	d[s] = 0;
	cnt[s] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto to : mp[x]){
			if(d[x] + 1 < d[to]){
				d[to] = d[x] + 1;
				cnt[to] = cnt[x];
				q.push(to);
			}
			else if(d[x] + 1 == d[to]) cnt[to] += cnt[x];
		}
	}
	for(int i = s + 1;i <= n;i++){
		if(cnt[i] == 2) ans++;
	}
}
void solve(){
	scanf("%lld%lld",&n,&d);
	clean(n);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n && a[j] - a[i] <= d;j++){
			mp[i].push_back(j);
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		bfs(i,dis,cnt,ans);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
