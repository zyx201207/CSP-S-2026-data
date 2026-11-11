#include<bits/stdc++.h>
using namespace std;
const int MX = 5000;
long long c,t,n,d,a[MX + 10],cnt = 0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i]; 
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				if((j-i)==3)cnt++;
			}
		}
	}
	cout <<cnt;
	return 0;
}
