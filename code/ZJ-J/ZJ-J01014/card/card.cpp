#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[300010],s[300010],v[300010],la[300010];
vector<ll> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=0;
		}
	}
	if(f)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				s[a[i-1]]=i-1;
			}
		}
		s[m]=n;
		for(int i=1;i<=n;i++)
		{
			cout<<s[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]==1)
			{
//				cout<<j<<endl;
				for(int k=la[a[j]];k<j;k++)
				{
					v[q.front()]=0;
					q.pop_back();
				}
			}
			q.push_back(a[j]);
			v[a[j]]=1;
			la[a[j]]=j;
		}
//		cout<<q.size()<<"!"<<endl;
		while(!q.empty())
		{
//			cout<<q.front()<<" ";
			s[q.front()]++;
			v[q.front()]=0;
			q.pop_back();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
