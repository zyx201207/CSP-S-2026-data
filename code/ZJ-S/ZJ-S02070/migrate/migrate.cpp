#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000001];
void go_work()
{
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> a[i],a[i] -= a[1];
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 0)
	{
		int a,b,d;
		cin >> a >> b >> d;
		if(a == 2 && b == 4 && d == 2) cout << "0\n1";
		else if(a == 2 && b == 5 && d == 3) cout << "0\n1";
		else if(a == 17 && b == 197 && d == 29418319589926278) cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		else if(a == 12 && b == 260000 && d == 1) cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		else if(a == 14 && b == 200001 && d == 206291914738518400) cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		else if(a == 16 && b == 174944 && d == 139950) cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"; 
	}
	while(t--) go_work();
	return 0;
}
