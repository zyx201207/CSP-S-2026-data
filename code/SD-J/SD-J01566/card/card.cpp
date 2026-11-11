#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct sz
{
	int s;
	bool x=0;
};
sz a[N];
int t[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++) a[j].x=0;
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j-1;k>=i;k--)
			{
				if(a[k].x==1) continue;
				if(a[j].s==a[k].s)
				{
					for(int l=k;l<j;l++)
					{
						if(a[l].x==1) continue;
						a[l].x=1;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(a[j].x==0) t[a[j].s]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
