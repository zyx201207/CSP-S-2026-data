//40%-50%
#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=-1;
int n,m;
long long ad(long long x,long long y)
{
	int xc[35],yc[35],ac[35];
	memset(xc,0,sizeof(xc));
	memset(yc,0,sizeof(yc));
	memset(ac,0,sizeof(ac));
	while(x)
	{
		xc[++xc[0]]=x%2;
		x/=2;
	}
	while(y)
	{
		yc[++yc[0]]=y%2;
		y/=2;
	}
	int l=max(xc[0],yc[0]),i;
	for(i=1;i<=l;i++)
	{
		if(xc[i]&&yc[i])
			ac[++ac[0]]=1;
		else
			ac[++ac[0]] = 0;
	}
	long long an=0,t=1;
	for(i=1;i<=ac[0];i++)
	{
//		cout<<ac[i]<<" ";
		an+= ac[i]*t;
		t*=2;
	}
	return an;
}
long long dfs(int step,int x,long long ax)
{
	if(step>=m)
	{
//		cout<<ans<<endl;
		ans=max(ax,ans);
		return 0;
	}
	int i;
	for(i=x+1;i<=n-(m-step)+1;i++)
	{
		long long y = ad(ax,a[i]);
//		cout<<step<<" "<<ax<<" "<<a[i]<<" ";
//		cout<< y <<endl;
		dfs(step+1,i,y);
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n-m+1;i++)
	{
		dfs(1,i,a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
