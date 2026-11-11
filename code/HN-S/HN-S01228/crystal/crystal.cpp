#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5; 
int m,n,a[N],dp[N],op;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dp[0]=1;
	for(int i=1;i<n;i++){
		dp[i]=a[i]-a[i-1]+dp[i-1];
	}
	for(int i=0;i<n;i++){
		if(dp[i]>m&&dp[i]!=dp[i-1]){
			op=i-1;
			break;
		}
		if(dp[i]==m){
			op=i;
			break;
		} 
	}
	cout<<op;
	return 0;
} 
