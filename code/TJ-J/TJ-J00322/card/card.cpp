#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,NN=3e5+5;
int n,m;
int a[N],b[NN],c[NN];
void work(int i)
{
	for(int j=i;j<=n;j++)
	{
		if(b[a[j]]==0)
			b[a[j]]=1;
		else
		{
			for(int x=j-1;x>=1;x--)
			{
				if(a[j]==a[x]) break;
				else b[a[x]]=0; 
			}
			b[a[j]]=1;
		}
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		work(i);
		for(int j=1;j<=m;j++)
		{
			if(b[j]==1) c[j]++;
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}
