/*#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxn=-1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		
	}
	cout<<maxn;
 } */
 #include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxn=-1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int fal=true;// 判断是否为特殊性质A 
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
			fal=false;
	}
	if(fal==true)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(m-i<0)
			{
				cout<<cnt;
				return 0;
			}
			m-=i;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int sum=m;
			long long cnt=0;
			for(int j=i;j>=1;j--)
			{
				long long cha=a[i]-a[j];
				if(sum-cha<0)
				{
					break;
				}
				else
				{
					cnt++;
					sum-=cha;
				}
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
	}
 } 
