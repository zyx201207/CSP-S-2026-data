#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;

long long c,T,n,d,ans,last,cnt,p,dist[maxn],tot[maxn],u,a[maxn];

void bfs(int x){
	queue<int> q;
	for(int i=1;i<=n;i++){
		dist[i]=1e18;
		tot[i]=1;
	}
	dist[x]=0;
	tot[x]=1;
	q.push(x);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=u-1;i>=1;i--){
			if(a[u]-a[i]>d){
				break;
			}
			if(dist[i]==dist[u]+1){
				tot[i]+=tot[u];
			}
			if(dist[i]>dist[u]+1){
				tot[i]=tot[u];
				dist[i]=dist[u]+1;
				q.push(i);
			}
		}
		for(int i=u+1;i<=n;i++){
			if(a[i]-a[u]>d){
				break;
			}
			if(dist[i]==dist[u]+1){
				tot[i]+=tot[u];
			}
			if(dist[i]>dist[u]+1){
				tot[i]=tot[u];
				dist[i]=dist[u]+1;
				q.push(i);
			}
		}
	}
}

void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j+=5){
			ans+=(tot[j]==2);
			ans+=(tot[j+1]==2);
			ans+=(tot[j+2]==2);
			ans+=(tot[j+3]==2);
			ans+=(tot[j+4]==2);
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		work();
	}
	return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/

