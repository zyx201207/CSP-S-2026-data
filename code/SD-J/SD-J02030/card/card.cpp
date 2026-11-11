#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100000]={},b[100000]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];} 
	for(int i=1;i<=n;i++)
	{
		int c[100000]={};
		for(int j=i;j<=n;j++)
		{
			c[a[j]]++;
			if(c[a[j]]>=2)
			{
				for(int k=1;k<=m;k++) c[k]=0;
				c[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++) b[i]+=c[i];
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
} 

