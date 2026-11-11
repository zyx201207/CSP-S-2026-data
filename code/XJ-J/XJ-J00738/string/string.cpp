#include<bits/stdc++.h>
using namespace std;

long long int n,a[200005],ans; char c[200005];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j,i_n,j_n;
	cin >> n;
	for (i=1; i<=n; i++)
		cin >> a[i] >> c[i];
	for (i=i_n=j_n=1,j=n; i<=n/2; i_n++,j_n++)
	{
		if (c[i]!=c[j])
			ans++;
		if (i_n>a[i])
		{
			i++;
			i_n=1;
		}
		if (j_n>a[j])
		{
			j--;
			j_n=1;
		}
	}
	cout << ans;
	return 0;
}
