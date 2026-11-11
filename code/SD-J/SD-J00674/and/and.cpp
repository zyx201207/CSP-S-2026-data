#include<bits/stdc++.h>
using namespace std;
int a[200005],c[105]; 
int main()
{
	freopen("and5.in","r",stdin);
	//freopen("and3.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	string s[200005];
	for(int i=1;i<=n;i++)
	{
		int x=a[i]; 
		while(x)
		{
			char ch=x%2+'0';
			s[i]+=ch;
			x/=2;
		}
	}
	int mx=-1e9;
	for(int i=1;i<=n;i++)
	{
		int as=s[i].size();
		mx=max(mx,as);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=s[i].size();j<mx;j++) s[i]+='0';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<mx;j++)
		{
			if(s[i][j]=='0') c[j]++;
		}
	}
	m=n-m;
	int ans=0;
	for(int i=mx-1;i>=0;i--)
	{
		if(c[i]==0) ans+=pow(2,i);
		else if(c[i]<=m)
		{
			ans+=pow(2,i);
			m-=c[i];
			c[i]=0;
			for(int j=1;j<=n;j++)
			{
				if(s[j][i]=='0')
				{
					for(int k=0;k<mx;k++)
					{
						if(s[j][k]=='0')
						{
							c[k]--;
							s[j][k]='1';
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
