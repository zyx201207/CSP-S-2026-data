#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=1e3+30;

int a[N];
int n,d;
int dis[N][N];
int dist[N][N];
int cnt[N][N];

void dfs(int ord,int now){
	if(now>n){
		return;
	}
	for(int i=1;i<=d;i++){
		dis[ord][now+i]=min(dis[ord][now+i],dis[ord][now]+1);
		dfs(ord,now+i);
	}
	return;
}

void dfs1(int ord,int now){
	if(now>n){
		return;
	}
	for(int i=1;i<=d;i++){
		dist[ord][now+i]=min(dist[ord][now+i],dist[ord][now]+1);
		if(dis[ord][now+i]==dist[ord][now+i]){
			cnt[ord][now+i]++;
		}
		dfs1(ord,now+i);
	}
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(dis,0x3f,sizeof(dis));
		memset(dist,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		cin>>n>>d; 
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dis[i][i]=0;
			dist[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			dfs(i,i);
		}
		for(int i=1;i<=n;i++){
			dfs1(i,i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<cnt[i][j]<<' ';
				if(cnt[i][j]==2){
					ans++;
				}
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}