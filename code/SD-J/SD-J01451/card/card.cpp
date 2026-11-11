#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];//模拟栈 
int c[300005];
bool d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)//i局
	{
		memset(d,0,sizeof(d));
		memset(b,0,sizeof(b));//每局开始前清空
		int p=0;//栈尾 
		for(int j=i;j<=n;j++)
		{
			if(d[a[j]])
			{
				for(int k=1;k<=p;k++)
				{
					if(b[k]==a[j])
					{
						p=k-1;
					}
				}	
			}
			p++;
			b[p]=a[j];//放进来 
			d[a[j]]=true;
		}
		for(int j=1;j<=p;j++)
		{
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
