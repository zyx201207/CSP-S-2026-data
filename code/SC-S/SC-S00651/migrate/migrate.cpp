#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[200005],dis[5005][5005],sum[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=0x3f3f3f3f3f;
				sum[i][j]=1;
			}
		}
		for(int i=0;i<=n;i++){
			dis[i][i]=0;
			sum[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int len=2;len<=n-i+1;len++){
				int j=i+len-1;
				for(int k=j-1;k>=i;k--){
					if(x[j]-x[k]>d){
						break;
					}
					if(dis[i][j]==dis[i][k]+1){
						sum[i][j]++;
					}
					else if(dis[i][k]+1<dis[i][j]){
						dis[i][j]=dis[i][k]+1;
						sum[i][j]=1;
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(sum[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 