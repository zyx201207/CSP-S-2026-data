#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int d[500010];
int aend=1;
int check(int x)
{
	for(int i=1;i<=aend;i++)
		if(d[i]==x) return i;
	return -1;
} 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
	{
		aend=1;
		for(int j=i;j<=n;j++)
		{
			int c=check(a[j]);
			if(c!=-1) 
			{
				aend=c-1;
			}
			d[++aend]=a[j];
		}
		for(int j=1;j<=aend;j++) b[d[j]]++;
		memset(d,0,sizeof(d));
		for(int k=1;k<=m;k++) cout<<b[k]<<' ';
		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}

