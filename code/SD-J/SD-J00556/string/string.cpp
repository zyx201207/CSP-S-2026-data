#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll N = 2e5 + 7;
struct node
{
	ll data;char x;
}A[N];
stack <node> S;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	ll lenth = 0;
	for (ll i = 1; i <= n; i ++) scanf("%lld %c",&A[i].data,&A[i].x),lenth += A[i].data;
	ll ans = 0;
	if (lenth & 1)
	{
		ll mid = (lenth + 1) / 2;
//		printf("%lld\n",mid);
		ll id = 0;
		for (ll i = 1; i <= n; i ++)
		{
//			printf("id=%lld\n",id);
			if (id == mid)
			{
				while (S.size())
				{
					node t = S.top();
					S.pop();
					if (t.data >= A[i].data)
					{
						t.data -= A[i].data;
						if (t.x != A[i].x) ans += A[i].data; 
						A[i].data = 0;
						S.push(t);
					} else
					{
						A[i].data -= t.data;
						if (t.x != A[i].x) ans += t.data;
					}
					if (!A[i].data) break;
				}
			}
			else if (id + A[i].data >= mid)
			{
				S.push((node){(mid - 1 - id),A[i].x});
				A[i].data -= (mid - id);
				id = mid;
//				printf("%lld\n",A[i].data);
				while (S.size())
				{
					node t = S.top();
					S.pop();
					if (t.data >= A[i].data)
					{
						t.data -= A[i].data;
						if (t.x != A[i].x) ans += A[i].data; 
						A[i].data = 0;
						S.push(t);
					} else
					{
						A[i].data -= t.data;
						if (t.x != A[i].x) ans += t.data;
					}
					if (!A[i].data) break;
				}
			}else
			{
				S.push(A[i]);
				id += A[i].data;
			}
		}
	}else
	{
		ll mid = lenth / 2 + 1;
		ll id = 0;
		for (ll i = 1; i <= n; i ++)
		{
//			printf("id=%lld\n",id);
			if (id == mid - 1)
			{
				while (S.size())
				{
					node t = S.top();
					S.pop();
					if (t.data >= A[i].data)
					{
						t.data -= A[i].data;
						if (t.x != A[i].x) ans += A[i].data; 
						A[i].data = 0;
						S.push(t);
					} else
					{
						A[i].data -= t.data;
						if (t.x != A[i].x) ans += t.data;
					}
					if (!A[i].data) break;
				}
			}
			else if (id + A[i].data >= mid)
			{
				S.push((node){(mid - id),A[i].x});
				A[i].data -= (mid - id);
				id = mid;
//				printf("%lld\n",A[i].data);
				while (S.size())
				{
					node t = S.top();
					S.pop();
					if (t.data >= A[i].data)
					{
						t.data -= A[i].data;
						if (t.x != A[i].x) ans += A[i].data; 
						A[i].data = 0;
						S.push(t);
					} else
					{
						A[i].data -= t.data;
						if (t.x != A[i].x) ans += t.data;
					}
					if (!A[i].data) break;
				}
			}else
			{
				S.push(A[i]);
				id += A[i].data;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
/*

 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/ 
