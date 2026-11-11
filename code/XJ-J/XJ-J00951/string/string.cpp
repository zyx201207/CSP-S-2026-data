#include <bits/stdc++.h>
using namespace std;

int n,ans;
string S;

struct node
{
	int num;
	char s;
}a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;++i) 
	{
		cin >> a[i].num >> a[i].s;
		for (int j = 1;j <= a[i].num;++j) S += a[i].s;
	}
	for (int i = 0;i <= S.size() / 2 - 1;++i) if (S[i] != S[S.size() - 1 - i]) ans++;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}