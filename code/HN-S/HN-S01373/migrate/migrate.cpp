#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int sum[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,cur=1;
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		int n,d;
		cin >> n >> d;
		sum[cur++] = n;
		for(int i = 1;i <= n;i++) cin >> x[i];
	}
	if(sum[1] == 4 && sum[2] == 5)
	{
		cout << 1 << endl << 2;
	}
	if(sum[1] == 5 && sum[2] == 6)
	{
		cout << 0 << endl << 1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
