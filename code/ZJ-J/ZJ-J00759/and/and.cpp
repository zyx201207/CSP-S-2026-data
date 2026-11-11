#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+2;
#define int long long

int a[N];
bool b[N];
int n,m;
priority_queue<int> s;
void f(int c,int ne)
{
	if(c==0)
	{
		s.push(ne);
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			f(c-1,ne&a[i]);
			b[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		b[i]=1;
		f(m-1,a[i]);
		b[i]=0;
	}
	cout<<s.top();
}