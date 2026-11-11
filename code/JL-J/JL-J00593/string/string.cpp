#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ok=1;
	long long ans=0;
	string s,stc;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		for(int i=1;i<=a;i++)
		{
			stc+=s;
		}
	}
	int m=stc.size()-1;
	for(int i=0;i<=m/2;i++)
	{
		int cnt=m;
		for(int i=cnt;i>=m/2;i--)
		{
			if(stc[i]==stc[cnt])
			{
				ok=1;
			}
			else
			{
				ans++;
				ok=0;
			}
		}
	}
	if(ok==1)
	{
		cout<<0;
	}
	else
	{
		cout<<ans;
	}
}