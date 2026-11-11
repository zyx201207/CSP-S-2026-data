#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10,M = 5e3 + 10;
int n,c;
int T;
long long a[N],d;
long long dis[M][M];
int cnt[M][M];
bool vis[M][M];
vector<int> e[M];
int ans;

void bfs(int s){
	queue<int> que;
	que.push(s);
	for(int i = s;i <= n;i++) dis[s][i] = INT_MAX,cnt[s][i] = 0LL,vis[s][i] = 0;
	dis[s][s] = 0LL;
	cnt[s][s] = 1;
	while(que.size()){
		int now = que.front();
		que.pop();
		if(vis[s][now]) continue;
		vis[s][now] = 1;
		for(auto i : e[now]){
			if(dis[s][i] > dis[s][now] + 1){
				dis[s][i] = dis[s][now] + 1;
				cnt[s][i] = cnt[s][now];
				que.push(i);
			}else if(dis[s][i] == dis[s][now] + 1) cnt[s][i] += cnt[s][now];
		}
	}
}

void clear(){
	ans = 0;
	for(int i = 1;i <= n;i++) e[i].clear();
}

void work1(){
	cin>>n>>d;
	clear();
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = n;i >= 1;i--){
		for(int j = i + 1;j <= n;j++){
			if(a[j]- a[i] > d) break;
			e[i].push_back(j);
		}
		bfs(i);
		for(int j = i + 1;j <= n;j++){
			if(cnt[i][j] == 2) ans++;
		}
	}
	cout<<ans<<endl;
}

void work2(){
	cin>>n>>d;
	for(int i = 1;i <= n;i++) cin>>a[i];
	long long now = a[2] - a[1];
	now = d / now;
	if(now <= 1) cout<<"0"<<endl;
	else cout<<max(n - now - now + 1,0LL)<<endl;
}

void work3(){
	cin>>n>>d;
	for(int i = 1;i <= n;i++) cin>>a[i];
	int k = 0;
	for(int i = 1;i <= n;i++){
		if(a[n] - a[i] <= d && a[i] - a[1] <= d) k = i;
	}
	ans = 0;
	if(k == n || k == n - 1) cout<<"0"<<endl;
	for(int i = k - 1;i >= 1;i--){
		if(a[k + 1] - a[i] <= d && a[k + 2] - a[i] > d) ans++;
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(0 <= c && c <= 10) work1();
		else if(11 <= c && c <= 12) work2();
		else if(13 <= c && c <= 14) work3();
	}
	return 0;
}
