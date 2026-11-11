#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,sj,k,x,y,qi,qj,zi,zj;
const int N=5e5+100;
int w[200005],a[505][N],t[505][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int v=1;v<=m;v++)
		cin>>w[v];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int r=1;r<=q;r++)
	{
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(t[i][1]=x) {qi=i;qj=1;}
			    if(t[i][j]=y) {zi=i;zj=j;}
			    sj=w[x]+w[y];
			    if(qi==zi) {
			    	          while(qj<zj)
			    	          {
			    	          	sj+=t[qi][qj];
			    	          	qj++;
							  }
				           } 
			    
			}
		}
	cout<<sj<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
