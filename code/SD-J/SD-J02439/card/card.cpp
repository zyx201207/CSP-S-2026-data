#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,m,a[N],qs[N];
bool p[N],pdA;
stack<long long>st;
int main()
{
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) pdA=1;
	}
	if(pdA==0)//ÌØÐÔA 
	{
		for(int i=1;i<=n;i++)
		{
			while(a[i]==a[i+1]) i++;
			cout<<i<<" ";
		}
		return 0;
	}
	int n1=n;
	while(n1!=0)
	{
		for(int i=n-n1+1;i<=n;i++)
		{
			if(p[a[i]]==1)
			{
				while(st.top()!=a[i])
				{
					p[st.top()]=0;
					st.pop();
				}
			}
			else
			{
				st.push(a[i]);
				p[a[i]]=1;
			}
		}
		while(!st.empty())
		{
			qs[st.top()]++;
			st.pop();
		}
		for(int i=1;i<=m;i++) p[i]=0;
		n1--;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<qs[i]<<" ";
	}
	return 0;
}

