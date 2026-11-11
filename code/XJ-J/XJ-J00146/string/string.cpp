#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n , a , num=0;
	int c;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		cin >> c;
		if(c[1] ==c[n] && a[1]==a[n]);
		{
			cout << "0";
			return 0;
		}
		else{
			num++;
		}
	}
	cout << num;
	return 0;
}
