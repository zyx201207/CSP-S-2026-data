#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
__int128 a[N];
__int128 pre[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		long long x;
		scanf("%lld",&x);
		a[i]=x;
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int maxx=0;
	int r=1;
	for(int l=1;l<=n;l++)
	{
		while(r<=n && (r-l+1)*a[r]-(pre[r]-pre[l-1])<=m) r++;
		maxx=max(maxx,r-1-l+1);
	}
	printf("%d",maxx);
	return 0;
}
/*
5 5
1 2 4 8 9
*/