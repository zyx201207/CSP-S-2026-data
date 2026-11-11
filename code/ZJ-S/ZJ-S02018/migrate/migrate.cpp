#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000005],d;
long long ans,cnt,dis;
void dfs1(long long fl,int u,int v){
	if(u==v){
		if(fl<dis)dis=fl,cnt=1;
		else if(fl==dis)cnt++;
		return;
	}
	for(int i=u+1;i<=v;i++)
		if(a[i]-a[u]<=d)dfs1(fl+1,i,v);
		else break;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(c==13||c==14){
			printf("%d\n",n);
			continue;
		}
		for(int u=1;u<=n;u++){
			for(int v=u;v<=n;v++){
				dis=1e9,cnt=0;
				dfs1(0,u,v);
				if(cnt==2)ans++;
				else if(cnt>=3||cnt==0)break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
