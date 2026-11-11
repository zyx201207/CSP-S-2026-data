#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
int n;
ll a[MAXN], pre[MAXN];
char c[MAXN];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	ll sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	int l = 1, r = n;
	ll sy = 0, ans = 0;
	while(true)
	{
		if(pre[l] < (sum >> 1)) // 加到现在还没超一半 
		{
			ll ls = sy;
			if(ls >= a[l]) // 右区间剩下的已经够这个左区间 
			{
				if(c[l] != c[r + 1])
				{
					ans += a[l];
				}
				sy -= a[l]; // 剩余- 
			}
			else // 否则 
			{
				if(c[l] != c[r + 1]) // 剩余的加上 
				{
					ans += sy;
				}
				while(true)
				{
					ls += a[r]; // 加上下一个区间 
					if(ls >= a[l]) // 已经够了 
					{
						if(c[l] != c[r])
						{
							ans += a[l] - (ls - a[r]);
						}
						sy = ls - a[l]; // 剩余重算
						r--;
						break; 
					}
					else // 否则 
					{
						if(c[l] != c[r])
						{
							ans += a[r];
						}
						r--;
					}
				}
			}
		}
		else // 否则 
		{
			ll ls = sy;
			if(ls >= (sum >> 1) - pre[l - 1]) // 右区间剩下的已经够这个区间 
			{
				if(c[l] != c[r + 1])
				{
					ans += (sum >> 1) - pre[l - 1];
				}
				sy -= (sum >> 1) - pre[l - 1]; // 剩余- 
			}
			else
			{
				if(c[l] != c[r + 1]) // 剩余的加上 
				{
					ans += sy;
				}
				while(true)
				{
					ls += a[r]; // 加上下一个区间 
					if(ls >= (sum >> 1) - pre[l - 1]) // 已经够了
					{
						if(c[l] != c[r])
						{
							ans += (sum >> 1) - pre[l - 1] - (ls - a[r]);
						}
						sy = ls - ((sum >> 1) - pre[l - 1]); // 剩余重算
						r--;
						break; 
					}
					else // 否则 
					{
						if(c[l] != c[r])
						{
							ans += a[r];
						}
						r--;
					}
				}
			}
			break;
		}
		l++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 前两题怎么都要输入字符，hyw 
// 10:03 才切掉，太菜了（笑点解析：想着优化常数，/2写的>>1，结果写成<<1了，卡我大半个小时） 
// 10:19 对拍怎么拍出错来了，给的数据好水 
// 10:23 第二种情况要改条件忘改了没绷住，T2 AC.
