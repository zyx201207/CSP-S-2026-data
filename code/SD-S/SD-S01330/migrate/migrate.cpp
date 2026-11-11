#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[505];
long long dis[505][505];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[j-1]>d){
					break;
				}
				long long x=lower_bound(a+1,a+n+1,a[j]-d)-a;
				if(x<i){
					dis[i][j]=1;
					continue;
				}
				dis[i][j]=min(dis[i][x]+1,dis[i][j]);
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long sum=0;
				for(int k=i+1;k<=j-1;k++){
					if(dis[i][k]==0x3f3f3f3f3f3f3f3f||dis[k][j]==0x3f3f3f3f3f3f3f3f){
						continue;
					}
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						sum++;
					}
				}
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
