#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long a[500005];
int dp[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

	scanf("%d %ld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		dp[i]=1;
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long s=m;
		int j=i-1;
		while(s>0&&j>0){
			if(s+a[j]>=a[i]){
				s-=(a[i]-a[j]);
				dp[i]++;
			}
			j--;
		}
//		cout<<dp[i]<<" ";
		ans=max(ans,dp[i]);
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

