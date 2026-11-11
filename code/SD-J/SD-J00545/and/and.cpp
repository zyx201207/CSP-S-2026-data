#include<bits/stdc++.h>
using namespace std;
long long q[200100],a[200100];
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxx=0;
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
		if(q[i]>maxx)
		{
			maxx=q[i];
		}
	}
	if(m==1)
	{
		cout<<maxx;
	}
	
	
	return 0;
} 
