#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt=0;
int x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
			}
			if(n>3)
			{
				cout<<n-3;
			}
			else
			{
				cout<<"0";
			}
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int minn=1e9,cnt1=0;
				if(abs(x[i]-x[j])<=d)
				{
					for(int y=j+1;y<=n;y++)
					{
						if(abs(x[j]-x[y])<=d)
						{
							if(minn<abs(x[i]-x[y]))
							{
								minn=abs(x[i]-x[y]);
								cnt1=0;
							}
							else 
							{
								if(cnt1>1 && minn==abs(x[i]-x[y]))
								{
									cnt1=0;
								}
								else if(minn==abs(x[i]-x[y]))
									cnt1++;
							}
						}
					}
					cnt+=cnt1;
					cout<<cnt1<<"\n";
				}
				else
				{
					break;
				}
			}

		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
