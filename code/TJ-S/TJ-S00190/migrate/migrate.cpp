#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[200005],num=0;
void solve1()
{
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d<2*(a[2]-a[1]))
		{
			cout<<0<<endl;
			continue;
		}
		else if(d>3*(a[2]-a[1]))
		{
			cout<<0<<endl;
			continue; 
		}
		else if(d<3*(a[2]-a[1])&&d>=2*(a[2]-a[1]))
		{
			long long chazhi=a[2]-a[1];
			for(int i=n;i>=1;)
			{
				if(i-3>=1)
				{
					num++;
					i-=3;
				}
				else
				{
					break;
				}
			}
			cout<<num<<endl;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>t;
	if(c==11||c==12)
	{
		solve1();
	}
	else if(c==13||c==14)
	{
		
	}
	else if(c>=15&&c<=18)
	{
		
	}
	else
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			if(d<a[2]-a[1])
			{
				cout<<0<<endl;
				continue;
			}
		} 
	}
	
	return 0;
} 
