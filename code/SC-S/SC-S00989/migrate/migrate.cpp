#include<bits/stdc++.h>
using namespace std;
long long x[2000003];
int far[2000003],cnt;
void dfs(int u,int lst,int now,int dis,int n){
	if(u==lst){
		if(now==dis) cnt++;
		return;
	}
	if(now>=dis) return;
	for(int j=u+1;j<=min(far[u],n);j++) dfs(j,lst,now+1,dis,n);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,ans=0;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				if(x[j]-x[i]<=d) far[i]=j;
				else break;
			}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				int now=i,dis=0,tag=0;
				while(now<j){
					if(far[now]==now){
						tag=1;
						break;
					}
					now=far[now],dis++;
				}
				if(dis<2||tag==1) continue;
				cnt=0,dfs(i,j,0,dis,n);
				if(cnt==2) ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}