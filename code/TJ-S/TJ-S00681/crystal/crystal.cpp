#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,m,a[maxn],dp[maxn]={1e15};
bool f;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		dp[i]=1;
	}
//	cout<<1;
	sort(a,a+n-1);
	int diff[n];//diff[i]意为a[i]-a[i-1]
	diff[0]=-1;
	for(int i=1;i<n;i++)
	{
		diff[i]=a[i]-a[i-1];
	}

	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
			if(diff[j]<=m){
				m-=diff[j];
				dp[i]+=1;//dp[i]选第i个时的最大值 
			}
		}
	}
	
	sort(dp,dp+n-1);
	printf("%lld",dp[n-1]+2);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
