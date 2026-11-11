#include<bits/stdc++.h>
using namespace std;
char s[200005][33];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int u=0;
		while(k)
		{
			s[i][u]=(k%2)+'0';
			u++;
			k/=2;
		}	
	}
	long long ans=0;
	for(int i=31;i>=0;i--)
	{
		int res=0;
		for(int j=1;j<=n;j++)
		{
			if(s[j][i]=='1')res++;
		}
		if(res>=m)
		{
			ans+=pow(2,i);
			for(int j=1;j<=n;j++)
			{
				if(s[j][i]!='1')
				{
					for(int k=0;k<31;k++)
					{
						s[j][k]=0;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
