#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],ans[300005];
map<int,int> c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	if(n>500)
	{
		for(int i=1;i<=m;i++)
		{
			if(c[a[i]]==0) cout<<0<<" ";
			else cout<<1<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		c.clear();
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]==0) 
			{
				c[a[j]]=j;
			}
			else
			{
				for(int k=j+1;k<=n;k++)
				{
					c[a[k]]=0;
				}
			}
		}
		ans[c[a[i]]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
