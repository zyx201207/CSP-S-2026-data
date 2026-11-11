//SN-J00793
//张意添
//西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool b[N];
long long a[N];
vector<long long> v[N];
long long n,m,len=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	len=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long a1=a[i];
		while(a1!=0)
		{
			v[i].push_back(a1%2);
			a1/=2;
		}
		b[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		while(v[i].size()<31)
		{
			v[i].push_back(0);
		}
	}
	for(int i=29;i>=0;i--)
	{
		long long cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(!b[j])continue;
			if(v[j][i]==1)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(!b[j])continue;
				if(v[j][i]==0)
				{
					b[j]=0;
					len--;
				}
			}
		}
		if(len==m)
		{
			break;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			if(ans==0)
			{
				ans=a[i];
			}
			else
			{
				ans&=a[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
