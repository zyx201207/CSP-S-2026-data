#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i= 1;i<=n;i++)
	{
		cin>>a[i]; 
		c[i]=a[i]+c[i-1];
	}
	sort(a+1,a+n+1);
	int l=0,r=1;
	
	int x=ceil((1.0*m/2));
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
