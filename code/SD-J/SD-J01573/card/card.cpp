#include <bits/stdc++.h>
using namespace std;
long long n,m; 
int a[100001],s[100001],c[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	stack<int>b;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			c[j]=0;
		}
		for(int j = i;j<=n;j++)
		{
			if(c[a[j]] == 1)
			{
				while(b.top()!=a[j])
				{
					c[b.top()]=0; 
					b.pop();
				}
				b.pop();
			}
			b.push(a[j]);
			c[a[j]] =1;
		}
		while(!b.empty())
		{
			s[b.top()]++;
			b.pop();
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
}
