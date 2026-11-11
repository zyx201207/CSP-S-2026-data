#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5000;
ll c,t,n,D,a[N],f[N][N];
void dfs(ll x,ll len,ll d){
	for(int i=x-1;i>=1;i--){
		if(a[x]-a[i]<=d){
//			cout<<i<<" "<<x<<endl;
			f[i][len]++;
			dfs(i,len+a[x]-a[i],d-a[x]+a[i]);
		}
		else{
			return ;
		}
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
//			cout<<x<<" "<<i<<endl;
			f[i][len]++;
			dfs(i,len+a[i]-a[x],d-a[i]+a[x]);
		}
		else{
			return ;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&D);
		if(n>=1e6){
			printf("0\n");
		}
		ll ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			dfs(i,0,D);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=D;j++){
				cout<<f[i][j]<<" ";
				if(f[i][j]==2){
					ans++;
				}
			}
			cout<<"\n";
		}
		printf("%lld\n",ans);
	}
	return 0;
}
