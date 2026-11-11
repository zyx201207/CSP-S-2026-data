#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000000+5],f[5010][5010],dp[5010][5010],cnt[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int x=a[2]-a[1];
			if(d<x){
				cout<<0<<endl;
			}else if(d==x){
				cout<<0<<endl;
			}else{
				d/=x;
				long long ans=0;
				for(long long i=1;i<d;i++){
					ans+=n%(d+i);
				}
				cout<<ans<<endl;
			}
		}
	}else{
		while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=2e18;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])<=d){
					dp[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<k;i++){
				for(int j=k+1;j<=n;j++){
					dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(dp[i][k]+dp[k][j]==dp[i][j]){
						cnt[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	}
	
	return 0;
}
