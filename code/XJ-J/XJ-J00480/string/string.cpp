#include<bits/stdc++.h>
using namespace std;
long long int n,x,c[200010];
char s[200010];
int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		cin>>s[i];
	}
	if(n%2==1)
	{
		for(int i=1,j=n;i<=n/2&&j>=n/2;i++,j--)
		{
			if(s[i]!=s[j])
			{
				x+=max(c[i],c[j]);
			}
			else if(c[i]!=c[j]&&s[i]!=s[j])
			{
				x+=abs(c[i]-c[j]);
			}
		}
	}
	else 
	{
		for(int i=1,j=n;i<=n/2,j>=n/2;i++,j--)
		{
			if(s[i]!=s[j])
			{
				x+=max(c[i],c[j]);
			}
			else if(c[i]!=c[j]&&s[i]!=s[j])
			{
				x+=abs(c[i]-c[j]);
			}
		}
	}
	cout<<x;
    return 0;
}
