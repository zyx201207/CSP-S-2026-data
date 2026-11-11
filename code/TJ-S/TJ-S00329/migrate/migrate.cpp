#include<bits/stdc++.h>
using namespace std;
long long n,d,a[999999],dist[999999],st[999999],vis[999999];
void dfs(long long x,long long sum){
	if(x==n){
		if(dist[n]==sum+1)st[n]++;
		else if(dist[n]>sum+1)st[n]=1;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i]==0 && abs(a[i]-a[x])<=d){
			vis[i]=1;
			if(dist[i]==sum+1)st[i]++;
			else if(dist[i]>sum+1)st[i]=1;
			dist[i]=min(dist[i],sum+1);
			dfs(i,sum+1);
			vis[i]=0;		
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++)dist[i]=999999999;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			st[i]=1;
		}
		for(int i=1;i<=n;i++)cin >> a[i];
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dist[j]=999999999;
			for(int j=1;j<=n;j++){
				vis[j]=0;
				st[j]=1;
			}
			dfs(i,0);
			for(int j=1;j<=n;j++)if(st[j]==2)ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
