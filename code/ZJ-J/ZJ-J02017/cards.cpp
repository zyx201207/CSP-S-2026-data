#include<bits/stdc++.h>
using namespace std;	
 stack<long long> qu;
 map<long long,int> mp;
 long long n,m,a[500005];
 long long ms[300005];
int main()
{
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		while(qu.size()!=0)
		{
		ms[qu.top()]++;
		qu.pop();
		}
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]]==0)
			{
			qu.push(a[j]);
			mp[a[j]]++;
			}
			else
			while(qu.top()!=a[j])
			{
			mp[qu.top()]--;
			qu.pop();
			}
		}
		for(int k=1;k<=m;k++)
			mp[k]=0;
			
	}
	ms[a[n]]++;
	for(int i=1;i<=m;i++)
		cout<<ms[i]<<' ';
}
