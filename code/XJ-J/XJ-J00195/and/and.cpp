#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,l[200005];
	cin >> a >> b;
	for (int i = 1;i <= a;i ++)
		cin >> l[i];
	cout << l[a];
	return 0;
 } 
