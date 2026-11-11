#include <bits/stdc++.h>
using namespace std;
int a[5000000],zd=0;
void dfs(int n,int m,int p,int o)
{
	if(m==0)
	{	if(zd<p)
		{
		zd=p;
		}
		 p=-1;
	
	return ;	
	}
	for(int i=o;o<=n&&i<=n;i++)
	{
		dfs(n,m-1,p&a[i],o+=1);
	}
}
int main()
{freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n1,m1;
cin>>n1>>m1;
for(int i=1;i<=n1;i++)
{
	cin>>a[i];
}
dfs(n1,m1,-1,1);
cout<<zd;
return 0;
}
