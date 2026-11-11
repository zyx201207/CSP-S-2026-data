#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int T;
int n,d,a[N],ans;

int g,mindis,cnt=0;
void dfs(int x,int dis){
	if(x==g){
		if(dis==mindis) cnt++;
		else if(dis<mindis){
			mindis=dis;
			cnt=1;
		}
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]>a[x]+d) break;
		dfs(i,dis+1);
	}
	
}

void solve(){
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int u=1;u<=n;u++) for(int v=u+1;v<=n;v++){
		g=v;
		mindis=n+1;
		cnt=0;
		dfs(u,0);
		if(cnt==2){
//			printf("%lld %lld %lld\n",mindis,u,v);
			ans++;
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ccc;
	scanf("%lld%lld",&ccc,&T);
	while(T--) solve();
	return 0;
}