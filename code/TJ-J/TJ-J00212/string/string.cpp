#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum[200005],cnt1[200005],cnt2[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	long long total = sum[n];
//	long long x = total/2,y=(total+1)/2+1,f1=1,f2=1,idx=0,idy=0;
//	for (int i = 1;i <= n;i++){
//		if (sum[i]>= x&&f1==1){
//			f1=0;
//			cnt1[++idx]=a[i]-(x-sum[i]);
//		}
//		if (sum[i]<x&&f1==1){
//			cnt1[++idx]=a[i];
//		}
//		if (sum[i]>=y)
//	}
	long long l = 1,r=n,sum1 = 0,sum2 =0,ans=0;
	while (total>1){
		long long x = a[l],y=a[r];
		if (x >= y){
			a[l]-=y;
			a[r]-=y;
			total = total -y-y;
			if (c[l]!=c[r])ans+=y;
		}
		else if (x<y){
			a[l]-=x;
			a[r]-=x;
			total = total - x - x;
			if (c[l]!=c[r])ans+=x;
		}
		if (a[l]==0)l++;
		if (a[r]==0)r--;
	}
	cout <<ans;
	return 0;
}
