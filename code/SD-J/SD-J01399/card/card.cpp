#include<bits/stdc++.h>
using namespace std;
struct abc
{
	int a;
	int b;
}c[500050];
bool px(abc x,abc y)
{
	if(x.a==y.a)
	{
		return x.b<y.b;
	}
	return x.a<y.a;
}
bool cmp[500050];
int ant[500050];
int sum[500050];
int ci[500050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].a;
		ci[i]=c[i].a;
		c[i].b=i;
	}
	sort(c+1,c+n+1,px);
	for(int i=1;i<=n;i++)
	{
		ant[c[i].a]++;
		cmp[c[i].b]=true; 
	}
	for(int i=1;i<=n;i++)
	{
		if(ant[c[i].a]==1)
		{
			cmp[c[i].b]=false; 
		}
	}
	for(int i=0;i<n;i++)
	{
		int l=1,r=n,mid=(l+r)/2;
		int xb=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(ci[i]==c[mid].a)
			{
				xb=mid;
				r=mid-1;
			}
			else if(ci[i]>c[mid].a) 
			{
				l=mid+1;
			}
			else if(ci[i]<c[mid].a)
			{
				r=mid-1;
			}
		} 
		if(xb!=-1)
		{
			if(c[xb+1].a==ci[i])
			{
				cmp[c[xb+1].b]=false;
				c[xb].a=-1;
				c[xb].b=-1;
				sort(c+1,c+n+1,px);
			}
			else
			{
				cmp[c[xb].b]=false;
			}
		}
		bool v=false,k=false;
		int o=-91;
		for(int j=n;j>=i+1;j--)
		{
			if(k==false)
			{
				sum[ci[j]]++;
				cout<<ci[j]<<" ";
			}
			if(o==ci[j])
			{
				k=false;
				v=false;
			}
			if(cmp[j]==true && v==false)
			{
				o=ci[j];
				v=true;
				k=true;
			}
			
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
