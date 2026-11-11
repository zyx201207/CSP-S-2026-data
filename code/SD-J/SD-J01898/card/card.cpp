#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,A[600000],C[600000],B[600000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long q,w,e,r,i,j,x,y;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>A[i]; 
	}
	if(n>500&&m>300)
	{
		for(i=1;i<=n;i++)
		{
			if(A[i]!=A[i+1])
			{
				cout<<i;
			}
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				if(B[A[j]]>0) 
				{
					q=j-1;
					while(A[q]!=A[j])
					{
						B[A[q]]--;
						q--;
					}
				}
				B[A[j]]++;
			}
			for(j=1;j<=m;j++)
			{
				if(B[j]>0) C[j]++;
				B[j]=0;
			}
		}
		for(i=1;i<=m;i++)
		{
			cout<<C[i]<<" "; 
		}		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 //<<fixed<<setprecision(2);
 
