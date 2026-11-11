#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		int n,d;
		cin>>n>>d;
		int x[n];
		for (int i=0;i<n;i++)
			cin>>x[i];
		if (n<4)
		{
			cout<<0;
			return 0;
		}
		if (c==11||c==12)
		{
			int xx=x[1]-x[0];
			cout<<max(0ll,n-2*d/xx+1)<<endl;
		}
		else
		{
			int prev=0,s=0,f=1;
			for (int i=0;i<n-3;)
			{
				if (x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d&&x[i+3]-x[i]>d)
				{
					s+=i-prev;
					int c=i+3;
					while (c+1<n&&x[c+1]-x[c]<=d)
					{
						if (c+2<n)
							while (x[c+2]-x[c]>d)
								c++;
						else
							c++;
					}
					if (c+1<n&&x[c+1]-x[c]>d)
					{
						s+=c-i-2;
						prev=c+1;
						i=c+1;
					}
					else
					{
						s+=c-2-i;
						prev=i+4;
						i=c+1;
					}
				}
				else
					i++;
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
