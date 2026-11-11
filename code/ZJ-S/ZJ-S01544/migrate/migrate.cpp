#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 5145
LL n,d,a[maxn];
LL c,T;
LL f[maxn][maxn];
LL mdist[maxn][maxn];
LL cnt[maxn][maxn];
void dfs(LL st,LL cur,LL dis){
	mdist[st][cur]=min(dis,mdist[st][cur]);
	LL i=cur+1;
	for(;a[i]-a[cur]<=d&&i<=n;i++){
		dfs(st,i,dis+1);
	}
}
void dfs2(LL st,LL cur,LL dis){
	if(dis==mdist[st][cur])f[st][cur]++;
	LL i=cur+1;
	for(;a[i]-a[cur]<=d&&i<=n;i++){
//		cout<<st<<" "<<i<<" "<<dis+1<<endl;
		dfs2(st,i,dis+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(mdist,0x3f,sizeof(mdist));
		cin>>n>>d;
		for(LL i=1;i<=n;i++){
			cin>>a[i];
			mdist[i][i]=0;
		}
		for(LL i=1;i<=n;i++){
			dfs(i,i,0);
		}
		for(LL i=1;i<=n;i++){
			dfs2(i,i,0);
		}
//		for(LL i=1;i<=n;i++){
//			for(LL j=1;j<=n;j++){
//				cout<<f[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		LL ans=0;
		for(LL i=1;i<=n-1;i++){
			for(LL j=i+1;j<=n;j++){
				if(f[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
