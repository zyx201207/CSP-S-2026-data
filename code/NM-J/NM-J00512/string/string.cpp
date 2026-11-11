#include<bits/stdc++.h>
using namespace std;
char a[200005];
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{	
		int num  =0;
		cin >> num >> a[i];
		for(int j = 1;j<=num;j++)
			s+=a[i];
	}
	int sum=s.size();
	for(int i = 0;i<=s.size()/2;i++)
	{
		if(s[i] != s[s.size()-i-1])
			ans++;
	}
	cout << ans;
	return 0;
}
