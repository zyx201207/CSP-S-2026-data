#include<bits/stdc++.h>
using namespace std;

int n,d;
int a[2000005];
int r[2000005];
int ans;

int dp[200005];


int solve(){
	
	ans=0;
	
	
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof dp);
		dp[0]=0;
		dp[i]=0;
		int from=a[i];
		for(int j=i+1;j<=n;j++){
			int now=a[j];
			if(a[j]-a[i]<=d){
				dp[j]=1;
				
			}else{
				if((a[j]-a[i])%d==0){
					dp[j]=1;
				}else{//cout<<dp[j]<<endl;
					for(int k=j;k>=k-d;k--){
						if(k<0){
							break;
						}
						
						dp[j]=dp[j]+dp[k];
					}
					if(dp[j]>d){
						dp[j]%=d;
					}
					
					
					if(dp[j]==2){
						ans++;
					}
				
				}
			}
		}
	}
	
	
	return ans;
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(r,0,sizeof r);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=100000;
			r[a[i]+100000]=i;
		}
		cout<<solve()<<endl;
	}

	return 0;
}
