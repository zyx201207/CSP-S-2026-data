#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,b;
	cin>>m>>n;
	int a[m][11],z[1000]={};
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=11;j++) a[i][j]=0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>b;
		z[i]=b;
	}
	sort(z,z+m);
	cout<<z[1];
	return 0;
} 
	
