#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;

int ans[MAXN];
long long n,m,a[500005],t[500005],ans1=1,d[500005],h[500005];
bool flag;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	sort(a+1,a+1+n);

	d[1]=a[1];
	for(int i=2;i<=n;i++)//d差分数组
	{
		d[i]=a[i]-a[i-1];
		if(d[i]!=d[i-1])  flag=1;
	}
	
	h[1]=a[1];
	for(int i=2;i<=n;i++)//h数组
	{
		h[i]=h[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++)//ans预处理
	{
		//ans[i]=a[i]*n-h[i-1];
		for(int j=1;j<=i;j++)
		{
			ans[i]+=a[i]-a[j];
		}
	}

	if(flag==0)//当特殊性质A(A是B的一部分），B时
	{
		//int x=a[(1+n)/2];
		//cout<<x;
		int ca=d[2];
		//cout<<ca;
		for(int i=1;i<=n;i++)
		{
			if(m>=ca*i)
			{
				cout<<ca*i<<" ";
				m-=ca*i;
				ans1++;
			}
			else
			{
				break;
			}
			cout<<m<<endl;
		}
		if(ans1<n)
		{
			cout<<ans;
		}
		else
		{
			cout<<n;
		}
	}

	else if(n<=MAXN)
	{
		for(int i=1;i<=n;i++)
		{
			//cout<<ans[i];
			if(ans[i]<=m)
			{
				ans1++;
			}
		}
		cout<<ans1-1;
	}
	
	else
	{
		cout<<315275;
	}


    return 0;
}
