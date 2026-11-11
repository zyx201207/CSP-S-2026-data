#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,ans=0;
	scanf("%ld %ld",&n,&m);
	long long int a[n],dp[n-1];
	for(int i=0;i<n;i++)
		scanf("%ld",&a[i]);
	sort(a,a+n);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n-1;i++)
		dp[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++){
		int j=i-1,s=0,t=0;
		while(s<=m && j>=0){
			t++;
			s+=dp[j];
			j--;
		}
		if(t>ans)
			ans=t;
	}
	printf("%d",ans);
	return 0;
}
