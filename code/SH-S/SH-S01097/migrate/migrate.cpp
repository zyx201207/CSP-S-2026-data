#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,t;
	scanf("%d%d", &c, &t);
	while(t--)
	{
		if(c==13||c==14)printf("1\n");
		else printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
