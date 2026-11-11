#include<bits/stdc++.h>
using namespace std;
int a[10000],dp[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i]=max(dp[i],dp[i-1]);
			sum+=dp[i];
		}
	}
	cout<<sum;
	return 0;
}
