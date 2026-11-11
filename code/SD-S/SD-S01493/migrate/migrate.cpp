#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long c, T, n, m;
long long a[N];
long long dis[N], cnt[N]; 
long long ans;
bool use[N];
void dfs(long long pos, long long w){
	dis[pos]=min(dis[pos],w);
	for(long long i=1;i<=n;i++){
		if(use[i] || i==pos || abs(a[i]-a[pos])>m)
			continue;
		use[i]=true;
		dfs(i,w+1);
		use[i]=false;
	}
	return;
}
void DFS(long long pos,long long w, long long st){
	if(dis[pos]==w && pos!=st)
		cnt[pos]++;
	for(long long i=1;i<=n;i++){
		if(use[i] || i==pos || abs(a[i]-a[pos])>m)
			continue;
		use[i]=true;
		DFS(i,w+1,st);
		use[i]=false;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(long long i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++)
				dis[j]=1e18;
			use[i]=true;
			dfs(i,0);
			DFS(i,0,i);
			use[i]=false;
			for(long long j=1;j<=n;j++){
				if(cnt[j]==2)
					ans++;
				cnt[j]=0;
			}
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}
