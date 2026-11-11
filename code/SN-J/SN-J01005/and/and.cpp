#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=-1e9;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((a[j]&a[i])>maxn)	maxn=(a[j]&a[i]);
		}
	}	
	cout<<maxn;			
	return 0;
}
