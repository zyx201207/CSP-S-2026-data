#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100];
bool flag;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			flag=1;
		}
	}
	if(!flag)
	{
		for(long long i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				cout<<i-1<<" ";
			}
		}
		cout<<n<<endl;
	}
	else if(m==1)
	{
		cout<<n<<endl;
	}
	else if(m==2)
	{
		if(a[n]==1)
		{
			long long anss=0;
			for(long long i=1;i<=n;i++)
			{
				if(a[i]!=a[n])
				{
					anss++;
				}
			}
			cout<<n<<" "<<anss<<endl;
		}
		else
		{
			long long anss=0;
			for(long long i=1;i<=n;i++)
			{
				if(a[i]!=a[n])
				{
					anss++;
				}
			}
			cout<<anss<<" "<<n<<endl;
		}
	}
	else
	{
		for(long long i=1;i<=m;i++)
		{
			cout<<n<<" ";
		}
		cout<<endl;
	}
	return 0;
}
