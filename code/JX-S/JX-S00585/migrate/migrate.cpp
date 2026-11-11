#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,d,a[N],dis[N],sum[N];
void dfs(int x){
	if(x==n+1){
		return;
	}
	for(int i=x+1;i<=n && a[i]-a[x]<=d;i++){
		if(dis[i]>dis[x]+1){
			sum[i]=0;
			dis[i]=dis[x]+1;
			dfs(i);
		}
		else if(dis[i]==dis[x]+1)	sum[i]++;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		int ans=0;
		for(int i=1;i<=n-3;i++){
			memset(dis,0x3f,sizeof dis);
			memset(sum,0,sizeof sum);
			dis[i]=0;
			dfs(i);
			//for(int i=1;i<=n;i++)	cout<<sum[i]<<' ';
			//cout<<'\n';
			for(int j=i+3;j<=n;j++){
				if(sum[j]==1)	ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
