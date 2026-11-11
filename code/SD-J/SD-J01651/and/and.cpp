#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m,w=0,maxn=-1e18;
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		w=a[i];
		for(int j=i+1;j<=i+m;j++)
		{
			w=a[j]&w;
		}
		maxn=max(w,maxn);
	}
	cout<<maxn;
	return 0;
 } 
