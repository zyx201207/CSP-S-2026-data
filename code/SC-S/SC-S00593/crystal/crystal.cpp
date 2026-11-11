#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int read()
{
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')t=t*10+c-'0',c=getchar();
	return t*f;
}
int n,m,a[N],sum[N],ANS;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid,ans;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			if(a[i]*mid-(sum[i]-sum[i-mid])<=m)l=mid+1,ans=mid;
			else r=mid-1;
		}
		ANS=max(ANS,ans);
	}
	cout<<ANS;
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/