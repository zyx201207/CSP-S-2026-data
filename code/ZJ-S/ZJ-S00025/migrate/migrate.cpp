#include<bits/stdc++.h>
using namespace std;
int c,T;
long long a[2000006];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		long long n,m;
		bool b=0;
		cin >> n >> m;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			if(i>=2)
			{
				if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				{
					b=1;
				}
			}
		}
		if(b==0)
		{
			m/=a[1]-a[0];
			if(m<=1) cout << "0" << endl;
			else if(m>=n) cout << "0" << endl;
			else cout << n-m*2+1 << "\n";
		}
		else
		{
			cout << "0" << endl;
		}
	}
}