#include<bits/stdc++.h>
using namespace std;
long long n,x,y,ans;
long long A[300000];
char C[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>A[i];
		cin>>C[i];
	}
	x=1;
	y=n;
	while(x!=y)
	{
		if(A[x]>A[y])
		{			
			if(C[x]==C[y])
			{				
				A[x]=A[x]-A[y];	
				y--;
				continue;
			}
			else
			{
				ans=ans+A[y];
				A[x]=A[x]-A[y];
				y--;
				continue;
			}
		}
		else if(A[x]<A[y])
		{
			if(C[x]==C[y])
			{
				A[y]=A[y]-A[x];
				x++;
				continue;
			}
			else
			{
				ans=ans+A[x];
				A[y]=A[y]-A[x];
				x++;
				continue;
			}
		}
		else if(A[x]==A[y])
		{
			if(C[x]==C[y])
			{
				x--;
				y--;
			}
			else
			{
				ans=ans+A[x];
				x--;
				y--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
