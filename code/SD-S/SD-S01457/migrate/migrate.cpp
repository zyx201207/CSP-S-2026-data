#include<bits/stdc++.h>
#define ll long long
#define re register
#define pa pair
using namespace std;
const int N=5e5+5;
const ll INF=INT_MAX;
ll a[N],c,n,d,ans,dis[N],num[N],jj;
void dfs(ll u,ll dep){
	
	if(dep<dis[u]){
		dis[u]=dep;num[u]=1;
	}else{
		if(dep==dis[u])num[u]++;
		else return ;
	}
	int j=u+1;
	while(a[j]<=a[u]+d&&j<=n){
		dfs(j,dep+1);
		j++;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(re int i=1;i<=n;i++)cin>>a[i];
		for(re int i=1;i<=n-3;i++){
			for(re int j=i;j<=n;j++)dis[j]=INF,num[j]=0;
			dfs(i,0);
			for(re int j=i;j<=n;j++)if(num[j]==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
