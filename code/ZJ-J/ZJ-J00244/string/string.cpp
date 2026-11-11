#include <bits/stdc++.h>
using namespace std;
string a[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long k,ans=0,m,x=0,c=0,j;
	string n;
	cin >> k;
	for(long long i=1;i<=k;i++)
	{
		cin >> m;
		cin >> n;
		c += m;
		m += x;
		x += 1;
		for(long long l=x;l<=m;l++)
		{
			a[l] = n;
		}
		x = m;
	}
	j = c;
	for(long long i=1;i<=c;i++)
	{
		if(j == i)
		{
			if(a[j] != a[i])
			{
				ans += 1;
			}
			cout << ans << endl;
			return 0;
		}
		if(a[j] != a[i])
		{
			ans += 1;
		}
		j -= 1;
	}
	cout << ans << endl;
	return 0;
}
