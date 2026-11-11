#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
string c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int cnt=0;
	string s="";
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j=1;j<=a[i];j++)
			s += c[i]; 
	}
	for (int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		cnt++;
	}
	cout << cnt;
	return 0;
}
	
