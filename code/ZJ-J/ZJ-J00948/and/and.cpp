#include<bits/stdc++.h>
using namespace std;
map<int,map<int,bool> > mp;
bool a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int k=0;
		while(x!=0)
		{
			mp[i][++k]=x%2;
			x/=2;
		}
		mx=max(mx,k);
	}
	bool s[100];
	for(int i=mx;i>=1;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(mp[j][i]==1&&a[j]==0) cnt++;
		}
		if(cnt>=m)
		{
			s[i]=1;
			for(int j=1;j<=n;j++)
			{
				if(mp[j][i]==0&&a[j]==0)
				{
					a[j]=1;
				}
			}
		}
		else s[i]=0;
	}
	int x=0;
	for(int i=mx;i>=1;i--)
	{
		x=x*2+s[i];
	}
	cout<<x;
}

