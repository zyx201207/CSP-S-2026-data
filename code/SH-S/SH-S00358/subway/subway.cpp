#include<bits/stdc++.h>
using namespace std;
long long l,n,m,d,o,a[1009],b[1009][1009],c[1009];
void dfs(int s,int x,int cs,int y,long long jl,int bs)
{
    if(b[cs][y]!=0&&jl>b[cs][y]||bs>=n)return;
    if(x==y)
	{
	    if(b[cs][y]==0)b[cs][y]=jl;
		else b[cs][y]=min(b[cs][y],jl);
		return;
	}
	c[x]++;
	for(int i=1;i<=m;i++)
	{
		
		if(b[x][i]!=0&&i!=x&&c[i]==0)
		{
			if(b[s][x]+b[x][i]<=b[s][i]||b[s][i]==0){b[s][i]=b[s][x]+b[x][i];b[i][s]=b[s][i];}
			dfs(x,i,cs,y,jl+b[x][i],bs+1);
		}
	}
	c[x]--;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>l>>n>>m>>d>>o;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		long long q[2*k+9];
		for(int j=1;j<=2*k;j++)
		{
			cin>>q[j];
		}
		for(int j=1;j<=2*k;j+=2)
		{
			for(int p=3;p<=2*k;p+=2)
			{
				if(b[q[j]][q[p]]==0)b[q[j]][q[p]]=q[j+1]+q[p+1];
				else b[q[j]][q[p]]=min(b[q[j]][q[p]],q[j+1]+q[p+1]);
				if(b[q[p]][q[j]]==0)b[q[p]][q[j]]=q[p+1]+q[j+1];
				else b[q[p]][q[j]]=min(b[q[p]][q[j]],q[p+1]+q[j+1]);
			}
		}
	}
	for(int i=1;i<=o;i++)
	{
		long long x,y;
		cin>>x>>y;
		if(b[x][y]==0)dfs(0,x,x,y,0,1);
		cout<<a[x]+a[y]+b[x][y]<<endl;
	}
} 
