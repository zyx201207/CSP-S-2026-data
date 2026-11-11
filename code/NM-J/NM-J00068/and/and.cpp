#include <bits/stdc++.h>
using namespace std;
long long a[100010],dp[100010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mann=INT_MIN;
	int loc;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mann){
			loc=i;
			mann=a[i];
		}
	}
	mann=0;
	for(int i=1;i<=n;i++)
		if(a[i]>mann&&a[i]<a[loc])
			mann=a[i];
	cout<<mann;
/*	int t=a[1];
	a[1]=a[loc];
	a[loc]=t;
	for(int i=0;i<=m;i++){

		dp[i]=minn;
	}*/
/*	for(int h=1;h<=n;h++){
		swap(a[1],a[h]);
		for(int i=1;i<=n;i++)
			dp[i]=a[i];
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(i!=2)
					dp[j]=max(dp[j-1]&a[i],dp[j]);
				else
					dp[j]=dp[j-1]&a[i];
			}
		}
	}
	cout<<dp[m];*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
