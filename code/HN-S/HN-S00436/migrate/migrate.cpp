#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifdef LOCAL
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#else
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	return;
}
void fast_read(){
#ifndef cin
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	return;
}
int n;
#define ll long long
ll d;
const int N=2e6+10;
ll x[N];
void input(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	return;
}
int cnt[N];
int st[N];
bool vis[N];
void reset(){
	for(int i=1;i<=n;i++){
		st[i]=0;
		cnt[i]=0;
		vis[i]=false;
	}
	return;
}
queue<int>q;
void bfs(int s){
	q.push(s);
	vis[s]=true;
	cnt[s]=1;
	while(q.empty()==false){
		int now=q.front();
		q.pop();
		for(int nxt=now+1;nxt<=n&&x[nxt]-x[now]<=d;nxt++){
			if(vis[nxt]==false){
				st[nxt]=st[now]+1;
				cnt[nxt]=cnt[now];
				vis[nxt]=true;
				q.push(nxt);
			}else if(st[nxt]==st[now]+1){
				cnt[nxt]+=cnt[now];
			}
		}
	}
	return;
}
ll ans;
void solve(){
	ans=0;
	for(int i=1;i<=n;i++){
		reset();
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2){
				ans++;
			}
		}
	}
	return;
}
int main(){
	file_init();
	fast_read();
	int c,t;
	cin>>c>>t;
	while(t--){
		input();
		solve();
		cout<<ans<<'\n';
	}
	return 0;
}
