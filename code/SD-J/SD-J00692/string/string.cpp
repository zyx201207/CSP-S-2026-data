#include <bits/stdc++.h>
using namespace std;
vector <char> v;
int n,m,ans;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> m >> c;
		for(int j = 1;j <= m;j++)
			v.push_back(c);
	}
	int l = v.size();
	int mid = ceil(l / 2);
	for(int i = l;i > mid;i--)
	{
		if(v[l - i] != v[i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}
