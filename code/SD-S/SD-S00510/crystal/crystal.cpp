#include<bits/stdc++.h>
using namespace std;
const long long M = 3e18;
long long n,m,a[500050],c[500050],s[500050],s2[500050],maxx;
bool cmp(long long a,long long b)
{
	return a > b;
}
bool check(int l,int r)
{
	if((s2[r] - s2[l - 1]) - (r - l + 1) * s[l - 1] <= m)return 1;
	else return 0;
}
void lin()
{
	int l = 2,r = 4;
	cerr << "²âÊÔ£º" << (s2[r] - s2[l - 1]) - (r - l + 1) * s[l - 1] << "\n";
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	a[n + 1] = a[n];
	a[0] = M;
	for(int i = 1;i <= n;i++)
	{
		c[i] = a[i - 1] - a[i];
		s[i] = s[i - 1] + c[i];
		s2[i] = s2[i - 1] + s[i];
	}
	//lin();
	for(int l = 1,r = 0;l <= n;l++)
	{
		while(r + 1 <= n && check(l,r + 1) == 1)r++;
		maxx = max(maxx,(long long)r - l + 1);
		//cerr << l << " " << r << endl;
	}
	cout << maxx + 1 << "\n";
	return 0;
}
/*
( si + si+1 + ... + si+k ) - (k+1)*s[i-1]

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

4 25
-3 -5 -7 -7 

5 23
-1 7 9 0 -5 
10 2 0 9

5 or 4

*/

