#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],fl[300005],f[300005],z,s[300005],zl,r,p[300005],sum[300005];
struct node{
	int x,y;
}w[500005];
bool cmp(node x,node y)
{
	return x.y<y.y;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
		if(f[a[i]]>1)
		{
			z++;
			w[z].x=fl[a[i]];
			w[z].y=i-1;
			fl[a[i]]=i;
//			cout<<w[z].x<<' '<<w[z].y<<endl;
		}
		fl[a[i]]=i;
	}
//	cout<<endl;
	sort(w+1,w+1+z,cmp);
	zl=1;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<' '<<zl<<':'<<endl;
		r=zl;
		zl=0;
		for(int k=zl;k<=z;k++)
		{
			if(w[k].x>=i&&p[w[k].x]!=i&&p[w[k].y]!=i)
			{
//				cout<<"erase:"<<w[k].x<<' '<<w[k].y<<endl;
				for(int j=w[k].x;j<=w[k].y;j++)
				{
					if(p[j]!=i)
					sum[a[j]]++;
					p[j]=i;
				}
				if(zl==0)
				zl=k;
			}
		}
		for(int j=1;j<=m;j++)
		{
//			cout<<f[j]<<' '<<sum[j]<<endl;
			if(f[j]>sum[j])
			s[j]++;
			sum[j]=0;
		}
		f[a[i]]-=1;
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	cout<<s[i]<<' ';
	return 0;
}
