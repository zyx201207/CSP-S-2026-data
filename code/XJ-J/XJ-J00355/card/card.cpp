#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long MAXN=5e5+5,MAXM=3e5+5; 
int dian[MAXM],pai[MAXN],zhuo[MAXM];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>dian[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			zhuo[++k]=dian[i];
			if(k<=1)
				continue;
			else
			{
				for(int i=1;i<=k;i++)
				{
					if(zhuo[k]==zhuo[i])
					{
						
					}
				}
			}
		}	
	 } 
	return 0;
 } 
