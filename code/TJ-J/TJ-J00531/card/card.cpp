#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c) cout << 1;
	else cout << 0;
	if(a[0]==c[0]&&a[1]==c[1]) cout << 1;
	else cout << 0;
	return 0;
}
