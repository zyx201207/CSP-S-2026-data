#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5e3+6;
int n;
int x[N];
int minstep[N];
int ways[N];
void dfs1(int x1,int step){
	if(minstep[x1]!=0x3f3f3f3f3f3f3f3f)return;
	minstep[x1]=step;
	int d=0;
	while(x[x1+(++d)]-x[x1]<=d){
		dfs(int x1+d,step+1);
	}
}
void dfs2(int x1,int step){
	if(step==minstep[x1])ways[x1]++;
	int d=0;
	while(x[x1+(++d)]-x[x1]<=d){
		dfs(int x1+d,step+1);
	}
}
void solve(){
	int ans;
	for(int i=1;i<=n;i++){
		memset(minstep,0x3f,sizeof(minstep));
		memset(ways,0x3f,sizeof(ways));
		dfs1(i,0);
		dfs2(i,0);
		for(int i=1;i<=n;i++)ans+=(ways[i]==2);
	}
	printf("%lld",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%lld%lld",&C,&T);
	while(T--){
		memset(x,0,sizeof(x));
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		solve();
	}
	return 0;
}
