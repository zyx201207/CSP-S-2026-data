#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10,inf=INT_MAX;
long long c,T,n,d,ans,X[N],dp[N],CNT[N];
void Main(){
	cin>>n>>d;
	for(long long i=1;i<=n;i++){
		cin>>X[i];
	}
	ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			dp[j]=inf;
			CNT[j]=0;
		}
		dp[i]=0;
		CNT[i]=1;
		for(long long j=i+1;j<=n;j++){
			for(long long k=j-1;k>=i;k--){
				long long tmp=X[j]-X[k];
				if(tmp<=d){
					if(dp[k]+1<dp[j]){
						dp[j]=dp[k]+1;
						CNT[j]=CNT[k];
					}
					else if(dp[k]+1==dp[j]){
						CNT[j]+=CNT[k];
					}
				}
				else{
					break;
				}
			}
			if(CNT[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		Main();
	}
	return 0;
}
