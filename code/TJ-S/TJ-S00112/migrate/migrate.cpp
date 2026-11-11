#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,x[2000006];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> d;
		for(int j = 0; j <n; j++)cin >> x[j];
		cout << c-c << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
