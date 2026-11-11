#include<bits/stdc++.h>
using namespace std;

int c,t,n,d;
int a[200005];

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
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
