#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		int n, d;
		cin>>n>>d;
		int sum=0;
		if(d<2)
		{
			cout<<"0"<<endl;
			break;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1, a+1+n);
		for(int i=1;i<=n;i++)
		{
			if(a[i+a[2]-a[1]*2*d-1]) 
			{
				sum++;
			}

		}
		cout<<sum<<endl;
	}
}

