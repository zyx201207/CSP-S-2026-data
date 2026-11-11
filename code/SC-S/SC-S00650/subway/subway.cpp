#include<bits/stdc++.h>
using namespace std;
int w[50010];
struct s
{
	int t[10010];
	int a[10010];
}y[10010];
int main()
{
	int len;
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	int  c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		len=k;
		while(k!=0)
		{
			int j=1;
			cin>>y[i].a[j]>>y[i].t[j];
			j++;
			k--; 
		}
	}
	int qd;
	int zd;
	for(int i=1;i<=q;i++)
	{
		int time=0;
		time+=w[qd]+w[zd];
		cin>>qd>>zd;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=len;k++)
			{
				if(y[j].a[k]==qd)
				{
					time+=y[j].t[k];
				}
				if(y[j].a[k]==zd)
				{
					time+=y[j].t[k-1]+w[y[j].a[k-1]];
				}
			}
		}
		cout<<time<<endl;
	}
	return 0;
}