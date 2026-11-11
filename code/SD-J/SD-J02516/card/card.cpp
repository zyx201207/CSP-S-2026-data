#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],b[500005];
bool c[500005];
queue<int>qu;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			qu.push(b[j]);
			if(c[b[j]])
			{
				for(int k=j-1;b[k]!=b[j];k--)
				{
					c[qu.sush()]=0;
					qu.pop;
				}
				qu.pop();
				c[b[j]]=1;
			}
			else a[b[j]]=1;
		}
		for(int j=qu.size()-1;j>0;j--)
		{
			a[qu.sush()]++;
			qu.pop();
		}
		for(int j=1;j<=n;j++)c[j]=0;
	} 
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
