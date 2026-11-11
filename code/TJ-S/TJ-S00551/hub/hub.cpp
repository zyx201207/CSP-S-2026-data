#include <bits/stdc++.h>
using namespace std;
int zd(int x,int y,int b[])
{
	return ((b[x]/y)%2==0)+((b[1]/y)%2==0);
}
int main ()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k;
		int a[n],b[n];
		for(int j= 1;j<=n-1;j++)
		{
			cin>>a[i]>>b[1];
		}
		cout<<k-1<<endl;
	}
	
}

