#include<bits/stdc++.h>
using namespace std;
long long a[600000];
long long t[600000];
long long ans[600000];
stack<long long> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long k=1;k<=n;k++)
	{
		memset(t,0,sizeof(t));
		long long i=k,sum=0;
		while(i<=n)
		{
			t[a[i]]++;
			s.push(a[i]);
			sum++;
			if(t[a[i]]>1)
			{		
				do{			
					t[s.top()]--;
					s.pop();
					sum--;
				} while(s.top()!=a[i]);
			}
			i++;
		}
		for(long long i=1;i<=sum;i++)
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
