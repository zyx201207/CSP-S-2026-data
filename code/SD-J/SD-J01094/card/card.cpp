#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
int a[N],v[N],b[N];
struct str
{
	int x;
	bool f;
}z[N];
//a原数组 b备份数组 v 标记数组 x 位置 f 是否出现 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(z[a[j]].f==1)
			{
				for(int k=z[a[j]].x;k<=j-1;k++)
				{
					z[a[k]].f=0;
					z[a[k]].x=0;
					b[a[k]]=0;
				}
			}
			else
			{
				z[a[j]].f=1;
				z[a[j]].x=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]!=0)
			{
				v[b[j]]++;
			}
			else
			{
				b[j]=a[j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(v[i]!=0)
		{
			cout<<v[i]<<" "; 
		}		 
	}
	return 0;
}
