#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int cnt=0;
		int res=0;
		int cnt2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i==2)
			{
				res=x[i]-x[i-1];
				cnt++;
			}
			else 
			{
				if(i!=1)
				{
					if(x[i]-x[i-1]==res)
						cnt++;
				}
			}
		}
		// cout<<res<<" "<<cnt<<endl;
		if(cnt==(n-1))
		{
			int tt=d;
			d=d/res;
			// cout<<d<<endl;
			if(2*d>n || tt<=res || res==0)
			{
				// cout<<"ok!"<<endl;
				cout<<0<<endl;
			}
			else
			{
				int num2=d*2-1;
				cout<<n-num2<<endl;
			}
		}
		else
		{
			int pos=0;
			int fmxx=0;
			for(int i=2;i<=n-1;i++)
			{
				if(x[i]-x[1]<=d && x[n]-x[i]<=d)
				{
					if(i-1>3 && n-i<=3)
					{
						fmxx=max(fmxx,1ll);
					}
					else if(i-1<=3 && n-i>3)
					{
						fmxx=max(1ll,fmxx);
					}
					else if(i-1<=3 && n-i<=3)
					{
						fmxx=max(fmxx,2*1ll);
					}
				}
			}
			cout<<fmxx<<endl;
		}
	}
}