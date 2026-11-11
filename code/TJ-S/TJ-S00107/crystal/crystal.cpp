#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],len=1,cha,maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//	{
////		cha[i]=cha[i-1]+(a[i]-a[i-1])*(i-1);
//        cout<<a[i]<<' ';
//	}
	for(long long k=1;k<=n;k++)
	{
		long long i=k+1,cnt=0;
		while(cha<=m&&i<=n)
		{
			len++;
			if(i!=k+1) cnt+=(a[i]-a[i-1])*(i-1);
			i++;
			cha=cnt;
		}
		maxn=max(maxn,len);
		len=0;
	}
//	cha=0,len=0;
//	for(int i=n-1;i>=1;i--)
//	{
//		cha+=(a[i+1]-a[i])*(n-i);
//		if(cha>m)
//		{
//			maxn=max(maxn,len);
//			break;
//		}
//		len++;
//	}
//	cha[1]=0;
//	for(long long k=n;k>=1;k--)
//	{
//		if(cha[k]<=m) maxn=max(maxn,k);
////		cout<<cha[k]<<' '<<k<<' '<<maxn<<' ';
//	}
////	cout<<endl;
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long k=n;k>i;k--)
//		{
//			if(cha[k]-(a[k]-a[i])<=m) maxn=max(maxn,k-i+1);
////			cout<<cha[k]-(a[k]-a[i])<<' ';
//		}
////		cout<<endl;
//	}
	cout<<maxn;
	return 0;
}

