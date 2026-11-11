#include<bits/stdc++.h>
using namespace std;
long long m;
int n,a[500005];
long long dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		int cha;
		cha=a[i+1]-a[i];
		dp[i]=cha*i+dp[i-1];
	}
	for(int i=1;i<=n;i++){
		if(m<dp[i]){
			cout<<i;
			return 0;
		}	
	}
	
	
	
	return 0;
} 
