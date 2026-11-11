//SN-J01007
//¶­¹ú¶°
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[300005],len;
vector<int>c;
bool vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		c.clear();
		c.push_back(a[i]);
		c.push_back(0);
		vis[a[i]]=1;
		len=1;
		for(int j=i+1;j<=n;j++)
		{
			if(vis[a[j]])
			{
				int id=0;
				while(c[id++]!=a[j]);
				for(int k=id;k<c.size();k++)
					vis[c[k]]=0,c[k]=0;
				len=id;
			}
			else
			{
				if(c.size()==len+1)
					c.push_back(0),c[len++]=a[j];
				else
					c[len++]=a[j],c[len]=0;
				vis[a[j]]=1;
			}
		}
		for(int i:c)
		{
			if(i==0)
				break;
			ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
