#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z;
long long A[500500],B[300500],book[300500];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long i,j,k,l;
	cin>>n>>m;
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			cin>>A[i];
		}
		cout<<n<<" ";
	}
	else if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			cin>>A[i];
			if(A[i]==1)
			{
				x++;
			}
			else
			{
				y++;
			}
		}
		if(A[n]==1)
		{
			cout<<n<<" "<<y;
		}
		else
		{
			cout<<x<<" "<<n;
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			cin>>A[i];
			B[A[i]]++;
		}
		for(i=1;i<=m;i++)
		{
			cout<<B[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
