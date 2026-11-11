#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N];
long long pre[N][26];
long long sum[N];
int ch[N];
char c[5];
int find(long long x)
{
	int l = 1,r = n,mid,best;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(sum[mid] >= x)
		{
			best = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return best;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
		scanf("%s",c);
		sum[i] = sum[i - 1] + a[i];
		ch[i] = c[0] - 'a';
		for(int j = 0;j < 26;j++)
		{
			pre[i][j] = pre[i - 1][j];
			if(ch[i] == j)
			{
				pre[i][j] += a[i];
			}
		}
	}
	long long mid = (1 + sum[n]) / 2;
	long long cur = 0;
	long long res = 0;
//	printf("%lld\n",mid);
	for(int i = 1;i <= n;i++)
	{
		long long l = cur + 1;
		long long r = cur + a[i];
		if(l > mid) break;
		r = min(mid,r);
		long long L = sum[n] - r + 1;
		long long R = sum[n] - l + 1;
		int La = find(L);
		int Ra = find(R);
		long long tmp = pre[Ra][ch[i]] - pre[La - 1][ch[i]];
		if(ch[La] == ch[i]) tmp -= L - sum[La - 1] - 1;
		if(ch[Ra] == ch[i]) tmp -= sum[Ra] - R;
//		printf("%lld %lld %lld %lld %lld\n",l,r,L,R,tmp);
		res += R - L + 1 - tmp;
		cur += a[i];
		
	}
	printf("%lld",res);
	return 0;
}
/*
8
1 d
5 c
1 b
2 a
1 b
1 c
2 b
1 d

*/
