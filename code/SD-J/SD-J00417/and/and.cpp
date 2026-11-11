#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1,g;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	maxn=-1;
	if(m==2)
	{
		for(g=0;g<n;g++);
		{
			for(int j=0;j<n;j++)
			{
				if(j==g) j++;
				else maxn=max(maxn,a[g]&a[j]);
			}
		}
	}
	maxn=a[0];
	if(n==m) for(int i=1;i<n;i++) maxn&=a[i];
	cout<<maxn;
	return 0;
}

