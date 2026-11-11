#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int l;
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
		l+=a;
	}
	for(int i=0;i<l;i++)
	{
		if(s[i]!=s[l-1-i])
		{
			ans++;
			s[l-1-i]=s[i];
		}
	}
	cout<<ans;
	return 0;
}

