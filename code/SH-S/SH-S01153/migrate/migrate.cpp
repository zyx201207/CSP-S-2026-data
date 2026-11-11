#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll a[1000005];
ll dis[15],ways[15];
void dfs(ll nw,ll use){
	if(nw>n) return ;
	if(use==dis[nw]) ways[nw]++;
	if(use<dis[nw]||ways[nw]==0) dis[nw]=use,ways[nw]=1;
	for(ll i=nw+1;i<=n;i++){
		if(a[i]-a[nw]<=d) dfs(i,use+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll cc,tt;
	scanf("%d%d",&cc,&tt);
	while(tt--){
		scanf("%d%d",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(n<=9){
			ll ans=0;
			for(int i=1;i<=9;i++){
		    	for(int j=0;j<=10;j++) dis[j]=1e18,ways[j]=0;
				dfs(i,0);
				for(int j=i+1;j<=n;j++){
					if(ways[j]==2) ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
	//½â×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡ 
	//¿ªlong long !!!
}
/*
0 2
4 2
1 2 3 4
5 2 
1 2 3 4 5
*/

	
