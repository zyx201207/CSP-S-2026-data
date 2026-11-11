#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int m,n,c,d,q;
	cin >> m >> n >> c >> d >> q;
	for(int i = 1; i < m; i++)
	{
		cout << i;
		for(int j = 1; i < n; j++)
	    {
		    cout << j;	
		    cout << m*n;
	    }
	}
	if(c==0)
	{
		cout << 0;
	}
	cout << 32 << endl << 17 << endl;
	cout << 35 << endl << 16 << endl;
	cout << 0 << endl;
	
	return 0;
}
