#include <bits/stdc++.h>
using namespace std;
int a1,a2,a3,a4,a5,i,j,d,k,x,y;//a2地铁条数，a3地铁站数，a5出行计划数 
long long f[1000][1000],w[1000],q[500][1000],z[1000];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a1>>a2>>a3>>a4>>a5;
	for(i=1;i<=a3;i++){
		for(j=1;j<=a3;j++)
	      {
		   f[i][j]=-1;
		    }
		for(j=1;j<=a2;j++)
		{
			q[j][i]=-1;
		}
		z[i]=0;
	}
	for(i=1;i<=a3;i++) cin>>w[i];
	for(i=1;i<=a2;i++) 
	{
		cin>>d;
		for(j=1;j<=d;j++)
		{
			cin>>z[j]>>q[i][z[j]];
			for(k=j;k>=1;k--)
			{  if(q[i][z[j]]!=-1&&q[i][z[k]]!=-1){
				f[z[j]][z[k]]=q[i][z[j]]+q[i][z[k]];
				f[z[k]][z[j]]=f[z[j]][z[k]];
				}
			}
		}
	}
	for(int i=1;i<=a3;i++)
	{
		for(j=1;j<=a3;j++)
		{
		  if(i!=j){
			for(k=1;k<=a3;k++)
			{ if(f[i][k]!=-1&&f[k][j]!=-1){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
			}
		}
	}
	for(i=1;i<=a5;i++) 
	{
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y];
	}
	return 0;
}
