#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000],s[400000];
string ans,b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool t=0;
			int id;
			for(int k=1;k<=n;k++)
			{
				if((ans[k]-'0')==a[j])
				{
					t=1;
					id=i;
				}
			}
			if(t==1)
			{
				b="";
				for(int k=1;k<=id;k++)b[k]=ans[k];
				ans="";
				for(int k=1;k<=id;k++)ans[k]=b[k];
			}
			else ans+=a[j];
		}
		for(int j=1;j<=n;j++)s[ans[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}

