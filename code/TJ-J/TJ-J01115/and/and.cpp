#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	const int N=2*10e5;
	int n,m,a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long maxn=-99824;
	for(int v=1;v<=n;v++)
	{
		for(int j=v;j<=n-m;j++)
		{
			for(int k=j;k<=n-m-m;k++)
			{
				int as=(a[v]&a[j])&a[k];
				if(as>=maxn)
				{
					maxn=as;
				}
				
			}
		}
	}
	cout<<maxn;
}
