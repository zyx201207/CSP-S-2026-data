#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,m;
long long a[2000005];
long long minn[2000005];
long long maxx[2000005];
long long pre;
long long l,r;
long long p1,p2;
long long ans;
long long pp2;
int main()
{ 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> m;
		for (int i = 1;i <= n;i ++)
		{
			cin >> a[i];
		}
		for (int i = 1;i <= n;i ++)
		{
			l = r = i;
			while (a[i] - a[l] <= m && l >= 1)l --;
			minn[i] = ++ l;
			while (a[r] - a[i] <= m && r <= n)r ++;
			maxx[i] = -- r;
			//cout << minn[i] << " " << maxx[i] << endl;
		}
		pp2 = 1;
		p1 = p2 = 1;
		ans = 0;
		for (p1 = 1;p1 <= n;p1 ++)
		{
			while(maxx[p1] - minn[pp2] > 1 && pp2 <= n)pp2 ++;
			/*int dl = pp2;
			int dr = n;
			while (dl <= dr)
			{
				int mid = (dl + dr) / 2;
				if (maxx[p1] - minn[mid] > 1)
				{
					pp2 = mid;
					dl = mid + 1; 
				}
				else
				{
					dr = mid - 1;
				}
			}*/
			//cout << pp2 << endl;
			for (p2 = pp2;maxx[p1] - minn[p2] == 1 && p2 >= p1;p2 ++)
			{
				//cout << p1 << " " << p2 << endl;
				ans ++;
			}
		}
		for (int i = 1;i <= n;i ++)
		{
			minn[i] = maxx[i] = a[i] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}

//. .  . . .  . .      .      .     .
//5 3b 1 5 3b 1 1 6b 4 1 6b 4 2 7 5 2 5 3b 1 5 3b 1-
//____   ____   ____   ____   ___     ____   ____
















//33961573wwh
//16:20   T2 P用没有卡常完成（cout比printf快？） 
//16:42   尝试暴力T3
//qwq rp++
//		 CCCC	   CCCC	   FFFFFF
//	   CC		 CC		   FF
//	  CC		CC		  FFFFF
//	  CC		CC		  FF
//	   CCCC		 CCCC	 FF
//3.in/outWA   4.in/outTLE