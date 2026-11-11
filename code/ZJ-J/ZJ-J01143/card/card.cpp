#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300010],t=0,c[300010];
long long q[500010];
struct node{
	long long x;
	int cnt;
}b[300010];
int main()
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
		for(int j=i;j<=n;j++)
		{
			q[++t]=a[j];
			if(b[a[j]].cnt==1)
			{
				for(int k=1;k<=m;k++)
				{
					if(b[k].x<t && b[k].x>b[a[j]].x)
					{
						b[k].cnt=0;
					}
				}
				t=b[a[j]].x;
			}
			else
			{
				b[a[j]].cnt++;
				b[a[j]].x=t;
			} 
		}
		for(int j=1;j<=t;j++)c[q[j]]++;
		for(int i=1;i<=m;i++)
		{
			b[i].cnt=0;
		}
		t=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
