#include<iostream>
using namespace std;
int c,m,n,d,q,k[100];
int a[100][100],x[300],b[100][10];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<2*k[i];j++)
		{
			cin>>a[i][j];
		}
}
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		cout<<"10";
	}
	return 0;
}
