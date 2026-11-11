#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,u,v,ans,num;
long long x[2000005];
bool gzy=false;
void dfs(long long l,long long r,long long s){
	if((x[l+1]-x[l])>d)
		return;
	if((x[l]+d)>=x[r]){
		num++;
		return;
	}
	gzy=false;
	for(long long q=r-1;q>=l+1;q--){
		if(gzy==true&&(x[q]+d)>=x[s+1]&&(x[l]+d)>=x[q])
			dfs(q,r,0);
		if(gzy==false&&(x[l]+d)>=x[q]){
			gzy=true;
			s=q;
			dfs(q,r,0);
		}
	}
}
int main(){
	//mol Gzy mol wb
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(long long i=1;i<=t;i++){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(long long j=1;j<=n;j++)
			scanf("%lld",&x[j]);
		for(long long j=1;j<=n;j++)
			for(long long k=j+1;k<=n;k++){
				num=0;
				dfs(j,k,0);
				if(num==2)
					ans++;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
