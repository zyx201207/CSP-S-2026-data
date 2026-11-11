#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,cnt,sum;
char c;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s[++cnt]=c;
	}
	for(int i=1;i<=cnt/2+1;i++)
		if(s[i]!=s[cnt+1-i])
			sum++;
	cout<<sum;
	return 0;
}
