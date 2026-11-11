#include <bits/stdc++.h>
using namespace std;

int n,cnt[5005][5005],dist[5005];
long long d,x[5005];

void dfs(int u,int now,int step){
	if(step>dist[now]) return;
	if(step<=dist[now]) dist[now]=step,cnt[u][now]++;
	for(int i=n;i>now;i--){
		if(x[i]-x[now]<=d) dfs(u,i,step+1);
	}
}

void solve(){
	memset(cnt,0,sizeof(cnt));
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n-3;i++){
		fill(dist,dist+n+5,0x3f3f3f3f);
		dfs(i,i,0);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,T;
	cin>>c>>T;
	while(T--) solve(); 
	return 0;
}
