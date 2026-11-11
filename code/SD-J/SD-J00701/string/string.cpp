#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200001]={0},ans=0;
	char c[200001];
	string s="";
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	int t=1;
	while (a[t]!=0)
	{
		for (int i=1;i<=a[t];i++)
		{
			s+=c[t];
		}
		t++;
	}
	for (int i=1;i<=s.size()/2+1;i++)
	{
		if (s[i-1]!=s[s.size()-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
