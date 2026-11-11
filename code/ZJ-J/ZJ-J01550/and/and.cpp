#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,s;
void d(int c,int y,int x)
{
	if(c<=s)
	{
		return ;
	}
	if(x==m)
	{
		s=max(s,c);
		return ;
	}
	for(int i=y+1;i<=n-m+x+1;i++)
	{
		d(c&a[i],i,x+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++)
	{
		d(a[i],i,1);
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
