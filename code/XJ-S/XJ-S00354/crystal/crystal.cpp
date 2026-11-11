#include <bits/stdc++.h>
using namespace std;
long long m,n,a[100001],maxn=1,maxm,s,m1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool b;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m-i;j++)
		{
			if(a[j]>a[j+1])
			{
				m1=a[j];
				a[j]=a[j+1];
				a[j+1]=m1;
			}
			/*for(int i=1;i<=m;i++)
			cout<<a[i]<<' ';
			cout<<endl; */
			
						
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		maxm=1;
		s=0;
		for(int j=i;j<=m;j++)
		{
			b=0;
			if(a[j]==a[j+1]&&j+1<=m)
			{
				b=1;
				maxm++;	
				if(maxm==m)
				{
					cout<<m;
					return 0;
				}
				//break;//为防止等于情况s错加 
			}
			//else if(a[j]!=a[j+1])
			if(b==0)
			{
				s+=(a[j+1]-a[j])*j;
				{
					if(s<n)
 					maxm++;	
				}
			}
			b=0;
			if(s<n);
			//a 
			else if(s==n)
			{
				maxm++;
				//cout<<maxm; 
				while(a[j+1]==a[j+2]&&j+2<=m)
				{
					j++;
					maxm++;
				}
				if(maxm>=maxn)
				maxn=maxm;
				break;
			}
			
			else
			{
				if(maxm>=maxn)
				maxn=maxm;
				break;
			}
			if(maxm==m)
			{
				cout<<m;
				return 0;
			}
		}
		//cout<<maxn;
		if(maxn==m)
		{
			cout<<m;
			return 0;
		}
	}
	cout<<maxn;
	
	return 0;
} 
