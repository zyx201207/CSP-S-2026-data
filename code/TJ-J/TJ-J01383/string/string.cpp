#include <bits/stdc++.h>
using namespace std;
int n;
long long sum,ans;
struct node{
	int x;
	char c;
}a[100010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].x >> a[i].c;
		sum += a[i].x;
		for(int j = 1; j<=a[i].x; j++)
			s += a[i].c;
	}
	int j = 0;
	for(int i = sum -1 ; i>=sum/2; i--)
	{
		if(s[i] != s[j])
		{
			ans++;
		}
		j++;
	}
	cout << ans;
	return 0;
}
