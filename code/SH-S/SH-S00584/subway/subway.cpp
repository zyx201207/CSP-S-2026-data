#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,t[505],k,last,now,go[505][505],ans,lasttime,nowtime;
bool vis[505];
struct node{
	int qu,intime,outtime,bianhao;
};
vector<node> g[505];
void dfs(int now,int endd,int sum,int line,int out){
	if(now == endd){
		ans = min(ans,sum+t[endd]+out);
		return;
	}
	if(vis[now]) return;
	vis[now] = 1;
	for(auto x:g[now]){
		if(line != x.bianhao) dfs(x.qu,endd,sum+x.intime+out,x.bianhao,x.outtime);
		else dfs(x.qu,endd,sum,x.bianhao,x.outtime);
	}
	vis[now] = 0;
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> t[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k >> last >> lasttime;
		for(int j = 2;j <= k;j++){
			cin >> now >> nowtime;
			g[last].push_back({now,lasttime,nowtime,i});
			g[now].push_back({last,nowtime,lasttime,i});
			last=now;
			lasttime=nowtime;
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			if(i == j) continue;
			if(go[i][j]||go[j][i]) continue;
			ans = LLONG_MAX;
			dfs(i,j,t[i],0,0);
			go[i][j]=ans;
			go[j][i]=ans;
		}
	}
	for(int i = 1;i <= q;i++){
		int left,right;
		cin >> left >> right;
		cout << go[left][right] << endl;
	}
	return 0;
}
