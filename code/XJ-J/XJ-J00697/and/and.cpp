#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int b[67],a;
	for(int i=1;i<=62;i++)
	{
		a*=2;
		b[i]=a;
	}
	long long int n,m,q[200005],w[200005][200005]={0},l[200005]={0},jg[200005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
	}
	sort(q,q+n);
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(q[i]>0)
		{
			w[i][j]=q[i]%2;
			q[i]/=10;
			j++;
		}
		l[i]=j;
		j=1;
	}
	sort(l,l+n);
	for(int j=1;j<=l[n];j++)
	{
		jg[j]=w[n][j];
	}
 	for(int i=n-1;i>=n-m;i--)
 	{
 		for(int j=l[i];j>=1;j--)
 		{
 			
 			if(jg[j]==w[i][j])
 			{
 				jg[j]=1;
			}else
			{
			 	jg[j]=0;
			}
		}
	}
	long long int y=0;
	for(int i=l[n]+1,j=1;i>=1;i--,j++)
	{
		y+=jg[i]*b[j];
	}
	cout<<y;
	return 0;  
	
}