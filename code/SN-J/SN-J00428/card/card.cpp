#include<bits/stdc++.h>
using namespace std;
queue<long long>gay; 
long long n,m;
long long a[600005];
long long com[500006],a1[300005];
long long s1[400005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		//gay.pop();
		//gay.empty();
		//gay.front();
	} 
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			gay.push(a[j]);
			com[a[j]]++;
			if(com[a[j]]==2)
			{
				com[a[j]]=1;
				gay.pop();
				while(gay.front()!=a[j]) 
				{
					com[gay.front()]=0;
					gay.pop();
				}
			}
		}
		while(!gay.empty())
		{
			s1[gay.front()]++;
			if(s1[gay.front()]<=1) a1[gay.front()]++;
			//cout<<gay.front()<<" ";
			gay.pop();
		}
		//cout<<endl;
		for(int j=1;j<=m;j++)
		{
			com[j]=0;
			s1[j]=0;
		} 
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",a1[i]);
	}
	return 0;
}
