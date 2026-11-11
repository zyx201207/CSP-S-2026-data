#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int C;
ll n,d,a[2000005],ans;
int dis[2000005],cnt[2000005];
vector<int> e[2000005];
void bfs(int st){
	queue<int> q;
	for(int i=1;i<=n;i++)dis[i]=1e9,cnt[i]=0;
	q.push(st);
	dis[st]=0;
	while(q.size()){
		int t=q.front();q.pop();
		for(int i:e[t]){
			if(dis[t]+1<=dis[i]){
				dis[i]=dis[t]+1;
				cnt[i]++;
				if(cnt[i]==2)ans++;
				if(cnt[i]==3)ans--;
				q.push(i);
			}
		}
	}
}
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],e[i].clear();
	for(int i=1;i<n;i++){
		int j=i+1;
		while(a[j]-a[i]<=d&&j<=n){e[i].push_back(j);j++;}
	}
	for(int i=1;i<=n;i++)bfs(i);
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>C>>T;
	while(T--)solve();
	return 0;
}
