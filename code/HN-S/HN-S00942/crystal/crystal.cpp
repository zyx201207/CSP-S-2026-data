#include <bits/stdc++.h>
using namespace std;
#define int long long
#define wmax(a,b) ((a)>(b) ? (a) : (b))

const int N=5e5;
int a[N+105],prsum[N+105];
#define qsum(l,r) (prsum[(r)]-prsum[(l)-1])
deque <int> sfmax;

signed main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	scanf("%lld %lld",&n,&m);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++)
	{
		prsum[i]=prsum[i-1]+a[i];
	}
	
	int maxx1=0;
	for (int l=1,r=1; r<=n; r++)
	{
//		while (sfmax.size() && a[sfmax.back()]<=a[r])
//		{
//			sfmax.pop_back();
//		}
//		sfmax.push_back(r);
//		while (sfmax.size() && sfmax.front()<l)
//		{
//			sfmax.pop_front();
//		}
		
		
//		int maxx=a[sfmax.front()];
		int maxx=a[r];
//		printf("l:%lld r:%lld maxx:%lld\n",l,r,maxx); //MS
		while (maxx*(r-l+1)-qsum(l,r)>m)
		{
			l++;
		}
		maxx1=wmax(maxx1,(r-l+1));
		
//		printf("l:%lld r:%lld size:%lld\n",l,r,r-l+1); //MS
	}
	
	printf("%lld",maxx1);
	return 0;
}

/*
5 5
2
1 2 4 8 9

3
*/

/*
5 8
-3 -1 2 2 7

4
*/
