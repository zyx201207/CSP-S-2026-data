#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i] >> c[i];
	string s;
	s+='!';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i]; 
		}
	}
	long long ans=0;
	long long t=s.size()-1;
	for(int i=1;i<=t/2;i++)
	{
		if(s[i]!=s[t+1-i])
			ans++;
	}
	cout << ans;
}
