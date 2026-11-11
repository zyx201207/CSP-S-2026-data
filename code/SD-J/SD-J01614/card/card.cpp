#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5;
long long n,m,a[N+5],pz[N+5],zs[N+5]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long sum=0,p=0;
	while(p<=n)
	{
		p++;
		for(int i=1;i<=sum;i++)
		{
			if(pz[i]==a[p])
			{
				long long x=0;
				for(int j=i;j<=sum;j++)
				{
					pz[j]=0;
					x++;
				}
				sum-=x;
				break;
			}
		}
		sum+=1;
		pz[sum]=a[p];
		for(int i=1;i<=sum;i++)
		{
			zs[pz[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<zs[i]<<" ";
	}
	return 0;
}//^-_-^,I hope that i will have good luck; 
