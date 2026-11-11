#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string s;
char c[2][200005];
int n;
long long len,ans,a[2][200005],b[2][200005],d[400005];
char cha(int idx,long long pos)
{
	return c[idx][lower_bound(b[idx]+1,b[idx]+n+1,pos)-b[idx]];
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	cin >> n;
 	for(int i=1;i<=n;i++)
 	{
 		cin >> a[0][i] >> c[0][i];
 		len += a[0][i];
 		b[0][i] = d[i] = len;
	}
	for(int i=1;i<=n;i++)
 	{
 		a[1][i] = a[0][n-i+1];
 		c[1][i] = c[0][n-i+1];
 		b[1][i] = d[n+i] = b[1][i-1]+a[1][i];
	}
	sort(d+1,d+n*2+1);
	for(int i=0;i<n*2;i++)
 	{
 		if(d[i] == d[i+1])
 		{
 			continue;
		}
		if(cha(0,d[i]+1) != cha(1,d[i]+1))
		{
			ans += d[i+1]-d[i];
		}
	}
	cout << '\n' << ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
