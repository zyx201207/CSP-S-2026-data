#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
ll arr[2000010];
ll dis[310][310][310],sum[310][310][310];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll testid=read(),t=read();
	while(t--){
		ll n=read(),d=read();
		for(ll i=1;i<=n;i++){
			arr[i]=read();	
		}	
		arr[n+1]=3e18;
		if(n<=300){
			for(ll k=0;k<=n;k++) for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) dis[k][i][j]=1e9;
			for(ll i=1;i<=n;i++){
				ll pos=upper_bound(arr+1,arr+n+1,arr[i]+d)-arr-1;
				dis[0][i][i]=0,sum[0][i][i]=1;
				for(ll j=i+1;j<=pos;j++) dis[0][i][j]=dis[0][j][i]=sum[0][i][j]=1;
			}
			for(ll k=1;k<=n;k++){
		
				for(ll i=1;i<=n;i++){
					for(ll j=1;j<=n;j++){
						dis[k][i][j]=dis[k-1][i][j];
						sum[k][i][j]=sum[k-1][i][j];
						if(dis[k][i][j]>dis[k-1][i][k]+dis[k-1][k][j]){
							dis[k][i][j]=dis[k-1][i][k]+dis[k-1][k][j];
							sum[k][i][j]=sum[k-1][i][k]*sum[k-1][k][j];
						}else if(dis[k][i][j]==dis[k-1][i][k]+dis[k-1][k][j]&&i!=j&&j!=k&&i!=k){
							sum[k][i][j]+=sum[k-1][i][k]*sum[k-1][k][j];
						}
					}
				}
//				cout<<"k="<<k<<"\n";
//				for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)cout<<sum[k][i][j]<<" \n"[j==n];
//				cout<<"\n";	
//				for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)cout<<dis[k][i][j]<<" \n"[j==n];	
//				cout<<"\n\n\n";					
			}
			ll cnt=0;
			for(ll i=1;i<n;i++){
				for(ll j=i+1;j<=n;j++){
//					cout<<dis[n][i][j]<<" \n"[j==n];
					cnt+=(sum[n][i][j]==2);
				}
			}
			cout<<cnt<<"\n";
			continue; 
		}
		cout<<"0\n";
	}
	return 0;
}
