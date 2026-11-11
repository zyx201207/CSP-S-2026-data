#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[300005],s[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	b[a[n]] = n;
	if(a[n] != a[n - 2])
		b[a[n - 1]]++;
	for(int i = 1;i <= m;i++)
		cout << b[i] << " ";
	return 0;
}
