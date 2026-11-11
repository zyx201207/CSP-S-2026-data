#include <bits/stdc++.h>
using namespace std;
int n,c,t;
long long x[2000005],d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","W",stdout);
	cin >> c >> t;
	if(c==11||c==12)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)
			cin >> x[i];
		int sum=0;
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				if((x[j]-x[i])%d!=0&&(x[j]-x[i])*2%d==0)
					sum++;
		cout << sum << "\n";
	}
	return 0;
}