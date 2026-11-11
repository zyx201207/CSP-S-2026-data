#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n;
long long arr[N],m,dif[N],sum[N];
long long bs(long long pos)
{
	long long lt=pos,rt=n,mid,t,ret;
	while(lt<=rt)
	{
		mid=lt+((rt-lt)>>1);
		t=sum[mid]-sum[pos]-(pos-1)*(arr[mid]-arr[pos]);
		if(t<=m)
			lt=mid+1;
		else
			rt=mid-1;
	}
	return rt;
}
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long i;
	long long s=0,ans=-1;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&arr[i]);
	}
	sort(arr+1,arr+1+n);
	dif[1]=arr[i];
	for(i=2;i<=n;++i)
	{
		dif[i]=arr[i]-arr[i-1];
		sum[i]=sum[i-1]+dif[i]*(i-1);
	}
	for(i=1;i<=n;++i)
	{
		//printf("%lld %lld\n",bs(i),i);
		ans=max(ans,bs(i)-i+1);
	}
	printf("%lld",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
