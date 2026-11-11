#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]>d&&i!=1)
			{
				n=i-1;
				break;
			}
		}
		int num=d/(a[2]-a[1]);
		if(num*2-1<n-1)			cout<<"2\n";
		else if(num*2-1==n-1)	cout<<"1\n";
		else					cout<<"0\n";
	}
	return 0;
}

