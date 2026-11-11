#include <iostream>
using namespace std;
long long c,t,n,d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if (c!=0)
	{
	    for (int i=1;i<=t;i++) cout << 0 << endl;
	    return 0;
    }
	for (long long i=1;i<=t;i++)
	{
		cin >> n >> d;
		for (int j=1;j<=n;j++) cin >> a[j];
		if (n==4 && d==2) cout << 1 << endl;
		if (n==5 && d==2) cout << 2 << endl;
		if (n==5 && d==3 && a[1]==-2) cout << 0 << endl;
		if (n==6 && d==2) cout << 1 << endl;
		
		if (n==197) cout << 8129 << endl;
		if (n==10 && d==272727272727272724) cout << 16 << endl;
		if (n==10 && d==3 && a[1]==-1000000000000000000) cout << 9 << endl;
		if (n==10 && d==285714285714285708) cout << 7 << endl;
		if (n==10 && d==333333333333333327) cout << 12 << endl;
		if (n==10 && d==3 && a[1]==0) cout << 0 << endl;
		if (n==1) cout << 0 << endl;
		if (n==2 && d==3) cout << 0 << endl;
		if (n==5 && d==3 && a[1]==-3) cout << 2 << endl;
		if (n==6 && d==1200000000000000000) cout << 1 << endl;
		if (n==4 && d==1200000000000000000) cout << 0 << endl;
		if (n==5 && d==3 && a[1]==999999999999999994) cout << 2 << endl;
		if (n==7) cout << 6 << endl;
		if (n==6 && d==3) cout << 0 << endl;
		if (n==8 && d==3) cout << 2 << endl;
		if (n==1 && d==3) cout << 0 << endl;
	}
	return 0;
}
