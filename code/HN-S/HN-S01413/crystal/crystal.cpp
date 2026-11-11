#include<bits/stdc++.h>
using namespace std;
const int N=100000000;
int a[N][N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		cin>>a[j][i];
	for(int w=1;w<=m;w++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			if(a[i][w]>a[j][w])
			swap(a[i][w],a[j][w]);	
	for(int i=1;i<n;i++)
		s[i]=a[i+1][1]-a[i][1];
	while(m>0)
	{
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=m;j++)
	          {
          		a[i][j]+=s[i];	     
			     m-=s[i];
			  }
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)  
		if(a[i][i]==a[j][i])  
		sum++;
	cout<<sum;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
