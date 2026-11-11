#include<bits/stdc++,.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin >> m >> n;
	int a[10005];
	int b[10005];
	for(int i=1;i<=m; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+m+1);
	cout << m,n,4;
	return 0;
}
