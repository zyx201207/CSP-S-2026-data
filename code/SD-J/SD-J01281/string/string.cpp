#include <bits/stdc++.h>
using namespace std;
struct N
{
	long long a;
	char c;
}s[200005];
int n;
long long len,ans=0,sum=0;
string d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
		for (int j=1;j<=s[i].a;j++)
			d=d+s[i].c;
	}
	len=sum;
	for (int i=0;i<=len/2;i++)
	{
		if (d[i]!=d[len-i-1])
			ans++;
	}
	cout<<ans;
	return 0;
}
