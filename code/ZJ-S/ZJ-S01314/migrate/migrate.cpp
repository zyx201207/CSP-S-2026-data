#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+5;
int c,t,n;
LL d,x[N],ans,curstep;
LL dfs(int s,int e,int step){
	if(step>curstep)
		return 0;
	if(s==e){
		if(step==curstep)
			return 1;
		return 0;
	}
	LL ans=0;
	for(int i=s+1;x[i]-x[s]<=d;i++)
		ans+=dfs(i,e,step+1);
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",x+i);
		ans=0;
		for(int i=1;i+1<n;i++)
			for(int j=i+2;j<=n;j++){
				curstep=0;
				for(int k=i+1;k<=j;k=x[upper_bound(x+k,x+j+1,x[k]+d)-x-1])
					curstep++;
				if(dfs(i,j,0)==2)
					ans++;
			}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
