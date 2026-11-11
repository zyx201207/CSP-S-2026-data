#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,a[10000],l,r,k,t,m,b[10000],x,p;
string c,s;
long long int fun(long long int x,long long int y)
{
	if(p==0)
	return 0;
	for(i=1;i<=n;i++)
	{
		p=fun(x,y);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
			cin>>a[i];
			b[i]=fun(b[i-1],a[i]);
	}
for(i=1;i<=n;i++)
{
	if(b[i]>x)
	x=b[i];
}
	cout<<x;
	return 0;
	fclose(stdin);
	fclose(stdout);
}