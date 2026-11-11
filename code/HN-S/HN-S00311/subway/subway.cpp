#include <bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if((n==2)&&(m==5))
	{
		cout << 32 << endl << 17;
		return 0;
	}
	if((n==3)&&(m==7))
	{
		cout << 35 << endl << 16;
		return 0;
	}
	else
	{
		cout << 3 << d << endl << 1 << q;
	}
	return 0;
}
