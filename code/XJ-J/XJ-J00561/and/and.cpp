#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int maxx=-0x3f3f3f3f3f3f3f3f;
	do{
		int sum=0;
		for(int i=1;i<m;i++)
		{
			sum=a[i]&a[i+1];
		}
		maxx=max(maxx,sum);
	}while(next_permutation(a+1,a+n+1));
	cout<<maxx;
	return 0;
}