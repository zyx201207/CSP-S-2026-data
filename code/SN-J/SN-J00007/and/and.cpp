#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,a[n],m,b,c=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>b;
		a[i]=b;
		c=c+a[i];
	}
	c=c/n;
	cout<<c;
	return 0;
}
