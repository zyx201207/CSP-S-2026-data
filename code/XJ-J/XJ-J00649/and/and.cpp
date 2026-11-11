#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdin);
	int n,m,i,a[200005],t=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>t)
		{
			t=a[i];
		}
	}
	cout<<t;
	return 0;
	
}