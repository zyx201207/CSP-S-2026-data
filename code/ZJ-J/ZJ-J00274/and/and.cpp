#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010],dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	for(int i=2;i<=m;i++){

		for(int j=1;j<=n-m+1;j++){
			for(int k=j+1;k<=n;k++){
				dp[k]=max(dp[k],(dp[j]&a[k]));
			}      
		}
	}
	cout<<dp[n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

