//高一轩 SN-J00790 交大附中
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0;
	if(m==1)
	{
		//cout<<a[1]<<" "<<a[2]<<endl;
		cout<<a[1];
	}
	else if(m==2)
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt=a[i];
			for(int j=i+1;j<=n;j++)
			{
				cnt&=a[j];
				ans=max(ans,cnt);
				cnt=a[i];
			}
			
		}
		cout<<ans;
	}
	else if(m==n)
	{
		long long d=a[1];
		for(int i=2;i<=n;i++)
		{
			d&=a[i];
		}
		cout<<d;
	}
	else
	{
		long long dd=0;
		for(int i=1;i<=n;i++)
		{
			long long ddd=0;
			if(i==1) ddd=a[2];
			else ddd=a[1];
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					ddd&=a[j];
				}
			}
			dd=max(dd,ddd);
		}
		cout<<dd;
	}
	return 0;
}
