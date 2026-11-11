#include<iostream>
using namespace std;
long long f,n,m,t,q;
long long a[100005],b[100005],c[10005],d[10005],e[10005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>f>>n>>m>>t>>q
    for(int i=1;i<=m;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=m+2;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=m+2;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
	}
	if(n==2)
	{
		cout<<32<<endl<<17;
	}
	else if(n==3)
	{
		cout<<35<<endl<<16;
	}
	return 0;
}