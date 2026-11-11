#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int M=35;

int a[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	int maxa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	
	if(m==1)
	{
		cout<<maxa;
		return 0;
	}
	
	if(m==n)
	{
		int aa=a[1];
		for(int i=2;i<=n;i++)
		{
			aa=aa and a[i];
		}
		
		cout<<aa;
	}
	
	if(m==2)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxn=max(maxn,int(a[i] and a[j]));
			}
		}
		
		cout<<maxn;
	}
	
	cout<<maxa;
	return 0;
}
