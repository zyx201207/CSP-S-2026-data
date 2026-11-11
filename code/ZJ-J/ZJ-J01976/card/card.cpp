#include<bits/stdc++.h>
using namespace std;

long long a[200005],s[200005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int tt=1;tt<=n;tt++){
		long long dp[200005]={},id=1;
		for(int i=tt;i<=n;i++){
			if(dp[a[i]]!=0){
				int xiao=dp[a[i]];
				for(int j=1;j<=m;j++){
					if(dp[j]>=xiao){
						dp[j]=0;
					}
				}
				id=xiao;
				dp[a[i]]=id++;
			}
			else{
				dp[a[i]]=id++;
			}
		}
		for(int i=1;i<=m;i++){
			
			if(dp[i]!=0){
				s[i]++;
				
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" "; 
	}
	return 0;
}
