#include<iostream>
using namespace std;
int a[100],c[100],num[100];
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int b,d=0,e,p;
	for(int i=0;i<n;i++)
	{
		p=a[i];
		while(p!=0)
		{
			b=p%2;
			e=b+e*10;
			p=p/2;
			d++;
		}
	}
}
