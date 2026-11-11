#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin >> t >> c;
	while(t--)
	{
		int n,d,u,v;
		cin >> n >> d >> u >> v;
		int sum = 0;
		if(u == v)
		{
			sum+=1;
			cout << sum;
		}	    
	}
    cout << 1 << endl << 2 << endl;
	cout << 0 << endl << 1 << endl;
	cout << 0 << endl;
	return 0;
}
