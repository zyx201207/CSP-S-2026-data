#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long d,ans;
int c,t,n,e;
void dfs(int k,int to,int mi,int st){
	if(k==to){
		e++;
		return;
	}
	for(int i=k+1;i<=to;i++){
		if(a[i]-a[k]>d) return;
		dfs(i,to,mi,st+1);
		if(e==3) return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=0,y=i;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[y]>d) y=k-1,x++;
				}
				x++;e=0;
				dfs(i,j,x,0);
				if(e==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}