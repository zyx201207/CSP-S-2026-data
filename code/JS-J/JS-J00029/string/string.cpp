#include<bits/stdc++.h>
using namespace std;
long long n,ans,sm[200005],dm[200005],sum;
string s;
struct Str
{
	int a;
	char c;
	void read()
	{
		cin >> a >> c;
	}
}m[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		m[i].read();
		//sm[i]=m[i].a+sm[i-1];
		sum+=m[i].a;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m[i].a;j++)
		{
			s+=m[i].c;
		}
	}
	//for(int i=n;i>=1;i--)
	//{
	//	dm[i]=m[i].a+dm[i+1];
	//}
	for(int i=1;i<=sum/2;i++)
	{
		if(s[i-1]!=s[sum-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}

