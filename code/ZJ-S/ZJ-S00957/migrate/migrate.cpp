#include <bits/stdc++.h>
using namespace std;
long long a[2000010],b[2000010],dp[2000010];
void sot(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=i,sum=0;
		while(j>=1&&a[i]-a[j]<=d){
			j++;
		}
		b[i]=j+1;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[b[i]]+1;
	}
	cout<<dp[n]<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		sot();
	}
	return 0;
}