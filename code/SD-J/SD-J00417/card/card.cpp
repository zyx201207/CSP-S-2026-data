#include<bits/stdc++.h>
using namespace std;
int a[500010],nn[500010],mm[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,minn=500010;
	cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) nn[j]=0;
		for(int j=0;j<n-i+1;i++)
		{
			nn[a[i]]++;
			if(nn[a[i]]==2) minn=a[i];
		}
		for(int j=1;j<=minn;j++) mm[j]++;
	}
	for(int i=0;i<n;i++) cout<<mm[i]<<' ';
	return 0;
}

