#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,l[500001],k[501][500001],qf[100001],qe[100001],ti,xj[501],fl=-12,an=9999999999999999;

void df(int no,int en,int nu)
{
	if(no==en)
	{
		ti+=l[en];
		if(ti<=an)
		{
			cout<<ti<<endl;
			an=ti;
		}
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(k[i][no]!=0 && fl!=i)
		{
			ti+=k[i][no];
			for(int j=0;j<n;j++)
			{
				if(k[i][en]!=0)
				{
					ti+=k[i][en];
					df(en,en,nu);
				}
				else
				{
					for(int ij=0;ij<m;ij++)
					{
						if(k[i][ij]!=0 && ij!=no && xj[ij]!=0)
						{
							fl=i;
							ti+=k[i][ij];
							df(ij,en,nu);
						}
					}
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i];
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		for(int j=0;j<a;j++)
		{
			int b,c;
			cin>>b>>c;
			k[i][b]=c;
			for(int ij=0;ij<i;ij++)
			{
				if(k[ij][b]!=0)
				{
					xj[b]++;
				}
			}
		}
	} 
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		qf[i]=a;
		qe[i]=b;
	} 
	for(int i=0;i<q;i++)
	{
		ti+=l[qf[i]];
		df(qf[i],qe[i],i);
		ti=0;
		fl=-12;
		an=9999999999999999;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
