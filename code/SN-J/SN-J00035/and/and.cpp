#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[10000],y[10000];
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	cin>>a[i];
	int i=0;
	while(a[i]=0)
	{
		y[i]=a[i]&a[i+1];
		if(y[i]>y[0])
		y[0]=y[i];
	}
	cout<<y[0];
	return 0;
}
