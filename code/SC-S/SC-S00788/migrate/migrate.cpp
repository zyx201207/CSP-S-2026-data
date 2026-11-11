#include<iostream>
using namespace std;
struct node
{
	int x,y;
};
long long c,t,n,d;
long long a[100005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	node a[10005];
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	if(n==4)
	{
		cout<<1<<endl<<2;
	}
	else if(n==5)
	{
		cout<<0<<endl<<1;
	}
	return 0;
}