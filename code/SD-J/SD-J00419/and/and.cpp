#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200004];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;++i)ans&=a[m];
	printf("%d",ans);
	return 0;
}

