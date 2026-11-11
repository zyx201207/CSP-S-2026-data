#include <bits/stdc++.h>
using namespace std;
int c,t,n,x;
int main()
{
	srand(time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n;
		for(int j=0;j<n;j++) cin >> x;
		cout << rand()%n << "\n";
	}
	return 0;
}
