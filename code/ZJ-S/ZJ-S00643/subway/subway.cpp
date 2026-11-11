#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,e,e2,startx,endx;
int w[100010],a[100010],t[100010],a2[100010],t2[100010],hc[100010],hcz;
void check()
{
	for(int i=1;i<=e;i++)
		for(int j=1;j<=e2;j++)
			if(a[i]==a2[j])
				hc[a[i]]++;
}
/*int mintime()
{
	for(int i=1;i<=max(e,e2);i++)
		for(int j=1;j<=100010;j++)
		if(hc[i]!=0) hcz=a[i];
	if(start==1)
	{
		int zsend=hcz;
		
	}
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0) c=1;
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=m;j++) cin>>w[j];
		cin>>e;
		for(int j=1;j<=e;j++)
			cin>>a[j]>>t[j];
		cin>>e2;
		for(int j=1;j<=e2;j++)
			cin>>a2[j]>>t2[j];
		for(int j=1;j<=q;j++)
		{
			int u,v;
			cin>>u>>v;
			int start,end;
			for(int k=1;k<=e;k++)
			{
				if(a[k]==u) 
				{
					start=1;
					startx=k;
				}
				else 
				{
					start=2;
					for(int l=1;l<=e2;l++)
						if(a2[k]==u) 
							startx=l;
				}
			}
			for(int k=1;k<=e;k++)
			{
				if(a[k]==v) 
				{
					end=1;
					endx=k;
				}
				else
				{
					end=2;
					for(int l=1;l<=e2;l++)
						if(a2[k]==v) 
							endx=l;
				}
			}
			if(start==end&&start==1) 
			{
				for(int k=startx;k<=endx;k++)
				{
					int time=0;
					time+=t[k];
				}
			}
			if(start==end&&start==2) 
			{
				for(int k=startx;k<=endx;k++)
				{
					int time=0;
					time+=t2[k];
				}
			}
			//else
				//time=mintime();
			cout<<time;
		}
	}
	fclose(stdin);
	fclose(stdout);
}