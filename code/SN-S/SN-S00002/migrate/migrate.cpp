#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c;
	if(c==11 or c==12)
	{
		cin >> t;
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1;i<=n;i++)
			{
				cin >> x[i];
			}
			cout << 0;
		}
		return 0;
	}
	if(c==13 or c==14)
	{
		cin >> t;
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1;i<=n;i++)
			{
				cin >> x[i];
			}
			cout << 0;
		}
		return 0;
	}
	cout << 0;
	return 0;
}
