#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool cmp(long long x,long long y){
	return x>y;	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]); 
	sort(a+1,a+1+n,cmp);
	long long mx=0;
	for(long long i=1;i<=n-m;i++)
	{
		long long sum = a[i];
		for(long long j=i;j<=m;j++) sum = (sum&a[j]);
		mx = max(sum,mx);
	}
	printf("%d",mx);
	return 0;
 } 
