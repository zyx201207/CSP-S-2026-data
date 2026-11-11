#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[20000001],s[20000001],x,xs,ans;
void dfs(long long i,long long j,long long h){
	for(int u=i+1;u<=j;u++){
		if(a[u]-a[i]<=d){
			dfs(u,j,h+1);
		}
		if(i==j){
			if(x>h){
			x=h;
			xs++;
			}
			else{
				if(x==h){
					xs++;
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&t,&n,&d);
for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
}
for(int i=1;i<n;i++){
	for(int j=i+1;j<=n;j++){
		dfs(i,j,0);
		if(xs==2){
			ans++;
		}
		x=0,xs=0;
	}
}
	printf("%lld",ans);
	return 0;
	
}
