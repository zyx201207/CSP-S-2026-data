#include<iostream>
using namespace std;
long long n,m,tot;
int a[300005],b[300005],c[500005];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{	
		int k[500005]={};
		for(int j=i;j<=n;j++)
		{
			if(tot==0)
			{
				a[++tot]=c[j];
				k[c[j]]=1; 
			}
			else if(k[c[j]])
			{
				if(a[tot]!=c[j])
				{
					while(a[tot]!=c[j])
					{
						tot--;
					}
				}
				
			}
			else
			{
				a[++tot]=c[j];
				k[c[j]]=1;
			}
		}
		while(tot>0)
		{
			b[a[tot]]++;
			tot--;
		}
		
	 } 
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
 } 
//10 3
//3 1 2 1 3 2 3 1 2 1
