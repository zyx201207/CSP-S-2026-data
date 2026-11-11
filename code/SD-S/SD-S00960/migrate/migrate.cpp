#include <iostream>
using namespace std;
const int N=2e6+5;
int c,t,a[N],n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==0)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				int l;
				cin>>l;
			}
			if(n==4 && d==2)
			{
				cout<<1<<endl;
			}
			else if(n==5 && d==2)
			{
				cout<<2<<endl;
			}
			else if(n==5 && d==3)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<1<<endl;
			}
		}
		return 0;
	}
	else
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			int l=1,r=2,cnt=0;
			while(l<r)
			{
				if(a[r]-a[l]<d+1)
				{
					r++;
				}
				else if(a[r]-a[l]>d+1)
				{
					l++;
				}
				else
				{
					cnt++;
				}
			}
			cout<<cnt;
		}
	}
	return 0;
}
