#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+2;
#define int long long

int o[N];
map<int,int> s;
map<int,int> p;
int n,m;
void f(int w)
{
	int in;
	vector<int> a;
	a.push_back(0);
	for(int i=1;i<=m;i++)s[i]=0;
	for(int i=w;i<=n;i++)
	{
		in=o[i];
		if(s[in]>a.size())s[in]=0;
		
		if(s[in]==0)
		{
			a.push_back(in);
			s[in]=a.size();
		}
		else
		{
			a.erase(a.begin()+s[in],a.end());
		}
	}
	
	for(int i=1;i<a.size();i++)
	{
		p[a[i]]++;
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>o[i];
	}
	for(int i=1;i<=n;i++)
	{
		f(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<p[i]<<" ";
	}
}