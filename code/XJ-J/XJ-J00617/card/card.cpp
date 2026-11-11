#include<bits/stdc++.h>
using namespace std;
long long int i,n,m,a[500005],s[300005],j,t[300005],k,b[500005],x,y;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			if(t[a[i]]==1)
			{
				for(j=1;j<=k;j++)
				{
					if(b[j]==a[i])
					y=j;
				}
				for(j=k;j<=m;j++)
				{
					t[a[j]]=0;
					b[j]=0;
				}
				k=m-k+1;
			}
			if(t[a[i]]==0)
			{
				b[++x]=a[i];
				s[a[i]]++;
				t[a[i]]=1;
			}
		}
	}
	
	for(i=1;i<=m;i++)
	cout<<s[i]<<" ";
	return 0;
}