#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],buck[M]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		stack<int> desk;
		int ltbk[M]={0};
		for(int j=i;j<=n;j++)
		{
			if(ltbk[a[j]]==0)
			{
				ltbk[a[j]]=1;
				desk.push(a[j]);
			}else
			{
				while(desk.top()!=a[j])
				{
					ltbk[desk.top()]=0;
					desk.pop();
				}
			}
		}
		while(!desk.empty())
		{
			buck[desk.top()]++;
			desk.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<buck[i]<<' ';
	}
	return 0;
}
