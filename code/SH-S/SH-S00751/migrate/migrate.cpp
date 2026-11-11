#include <bits/stdc++.h> 
using namespace std;
int c,t;
int n[100005],d[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	bool a=false;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int j=1;j<n-1;j++)
		{
			if(x[j+2]-x[j+1]!=x[j+1]-x[j])
			{
				a=true;
			}
		} 
		if(a==false)
		{
			
		}
	} 
}
