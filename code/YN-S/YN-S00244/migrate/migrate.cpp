#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2000005;
struct node
{
	int location;
	int paths;
	int distance;
}a[maxn];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int iii=0;iii<t;iii++)
	{
		int n,m;
		int ans=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].location;
		}
		for(int i=0;i<n-1;i++)
		{
			a[i].paths=1;
			a[i].distance=0;
			for(int j=i+1;j<n;j++)
			{
				int minp=10000000,d=0;
				for(int k=j-1;k>=i&&(a[j].location-a[k].location<=m);k--)
				{
					if(a[k].distance<minp)
					{
						minp=a[k].distance;
						d=a[k].paths;
					}
					else
					{
						if(a[k].distance==minp)
						{
							d+=a[k].paths;
						}
					}
					
				}
				if(minp!=10000000)
				{
					a[j].paths=d;
					a[j].distance=minp+1;
				}
				else
				{
					a[j].paths=a[j].distance=0;
					break;
				}
				if(a[j].paths==2)
				{
					ans++;
				}
			}
			/*cout<<"###\n";
			for(int jjj=i;jjj<n;jjj++)
			{
				cout<<a[jjj].paths<<" ";
			}
			cout<<"\n";
			for(int jjj=i;jjj<n;jjj++)
			{
				cout<<a[jjj].distance<<" ";
			}
			cout<<"###\n";*/
		}
		cout<<ans<<"\n";
	}
	return 0;
}
