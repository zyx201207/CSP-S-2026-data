#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		if(i>t)
		{
			if(s[i]!=s[t])
			{
				ans++;
				s[i]=s[t];
			}
			else
			{
				continue;
			}
			t++;
		}
		else
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}