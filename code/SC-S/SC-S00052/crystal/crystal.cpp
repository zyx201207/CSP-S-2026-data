#include<bits/stdc++.h> 
using namespace std;
long long m;
long long c,n,cf,a[500100],dp[500100],jl,j,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i+1])f=1;;
	}
	sort(a+1,a+n+1);
	if(f==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i+1]=a[i+1]-a[i]+dp[i];
	}
	for(int i=1;i<=n;i++){
		int h=0;
		h+=dp[i];
		c++;
		if(h<=m&&h+dp[i+1]>m){
			jl=dp[i];
			j=i;
			break;
		}
	}
	for(int i=j;i<=n;i++){
		if(jl==dp[i])cf++;
	}
	cout<<cf+c-1; 
	return 0;
} 