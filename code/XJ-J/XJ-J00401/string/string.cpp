#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int a[100005];
int c[100005];
	int n;
	cin >> n;
	string s;
	long long L;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i] >> c[i];
		int pos = a[i];
	    for(int j=1;j<=a[i];j++)
		{
			s[n*pos+j]=c[i];
		}
		L += a[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==a[L+1-i])
		{
			ans++;
			ans--;
		}
		else
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}