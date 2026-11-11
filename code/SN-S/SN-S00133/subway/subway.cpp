#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int a[m],b[n][500001],k[n],r[q][2],sh[n][500001];
	for (int i = 0;i < m;i++)
	    cin >> a[i];
	for (int i = 0;i < n;i++)
	{
		cin >> k[i];
	    for (int j = 0;j < k[i];j++)
	        cin >> b[i][j];
	        cin >> sh[i][b[i][j]];
	}
	for (int i = 0;i < q;i++)
	{
		cin >> r[i][0] >> r[i][1];
	    int sum = a[r[i][0]] + a[r[i][1]] + xl(i);
	    
	    cout << sum << endl;
	}
	    
	
	return 0;
 }
int xl(int x)
{
	int z = 0;
	for (int i = 0;i < n;i++)
	{
	    for (int j = 0;j < k[i];j++)
	        if (b[i][j] == r[x][0] or b[i][j] == r[x][1])
	            z+=sh[i][b[i][j]];
	}
	return z;
}
