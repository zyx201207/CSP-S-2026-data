#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 5005 , M = 2000005;
ll c , T , n , d , a[M] , pre[M] , nxt[M] , sum[M] , f[M] , mns[M];

signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	scanf("%lld %lld" , &c , &T);
	if(c <= 10)
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &d);
			for(ll i = 1 ; i <= n ; i++) scanf("%lld" , &a[i]);
			ll ans = 0; sum[0] = 1;
			for(ll i = 1 ; i < n ; i++)
			{
				mns[i] = 0; f[i] = 1; sum[0] = 1;
				for(ll j = 1 ; j <= n ; j++) sum[j] = 0;
				ll stp = 1 , l = i;
				for(ll j = i + 1 ; j <= n ; j++)
				{
					while(a[j] - a[l] > d) {if(!(sum[mns[l]] -= f[l])) stp++; l++;}
					mns[j] = stp; sum[stp] += (f[j] = sum[stp - 1]);
					if(f[j] == 2) ans++;
				}
			}
			printf("%lld\n" , ans);
		}
	}
//	else if(c > 10 && c <= 12)
//	{
//		while(T--)
//		{
//			scanf("%lld %lld" , &n , &d);
//			if(n == 1 || n == 2) {printf("%lld\n" , 0); continue;}
//			for(ll i = 1 ; i <= n ; i++) scanf("%lld" , &a[i]);
//			ll stp = d / (a[2] - a[1]) , ans = 0;
//			for(ll i = 1 ; i < n - stp ; i++) ans += n - i - (stp - 1) - (n - i) / stp;
//			printf("%lld\n" , ans);
//		}
//	}
//	else if(c > 12 && c <= 14)
//	{
//		while(T--)
//		{
//			scanf("%lld %lld" , &n , &d);
//			if(n == 1 || n == 2) {printf("%lld\n" , 0); continue;}
//			for(ll i = 1 ; i <= n ; i++) scanf("%lld" , &a[i]) , pre[i] = nxt[i] = i;
//			ll l = 1; for(ll i = 1 ; i <= n ; i++)
//			{
//				while(a[i] - a[l] > d) l++;
//				pre[i] = l , nxt[l] = i;
//			}
//			for(ll i = l ; i <= n ; i++) nxt[i] = n;
//			ll pos; for(ll i = 1 ; i <= n ; i++)
//				if(a[i] - a[1] <= d && a[n] - a[i] <= d) {pos = i; break;}
//			ll ans = 0;
//			for(ll i = 1 ; i < pos ; i++)
//			{
//				ll tmp = nxt[i]; if(tmp == pos) tmp--; if(tmp == i) continue;
//				ans += nxt[tmp] - tmp - (tmp <= pos && nxt[tmp] >= pos);
//			}
//			printf("%lld\n" , ans);
//		}
//	}
//	else if(c > 14 && c <= 18)
//	{
//		
//	}
	else
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &d);
			for(ll i = 1 ; i <= n ; i++) scanf("%lld" , &a[i]);
			ll ans = 0; sum[0] = 1;
			for(ll i = 1 ; i < n ; i++)
			{
				mns[i] = 0; f[i] = 1; sum[0] = 1;
				for(ll j = 1 ; j <= n ; j++) sum[j] = 0;
				ll stp = 1 , l = i;
				for(ll j = i + 1 ; j <= n ; j++)
				{
					while(a[j] - a[l] > d) {if(!(sum[mns[l]] -= f[l])) stp++; l++;}
					mns[j] = stp; sum[stp] += (f[j] = sum[stp - 1]);
					if(f[j] == 2) ans++;
				}
			}
			printf("%lld\n" , ans);
		}
	}
	return 0;
}
