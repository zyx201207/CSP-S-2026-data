#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

LL a[N];
LL pre[N];

int n = 0;
LL m = 0;

int tar_i = 0;

bool cmp(LL x, LL y)
{
	return x < y;
}

int check(int cnt)
{
	LL sum = 0;
	
	LL need = a[tar_i] * cnt;
	
	if(tar_i < cnt) // 前面全算上 不够 
	{
		return 0;
	}
	
	sum = pre[tar_i] - pre[tar_i - cnt];
	
	// 能不能 凑数 cnt 个 a[tar_i] ? 
	
	if(sum <= need // 本身 必须小于，如果大于 无法逆转 
	&& sum + m >= need) // 可以通过 仅有的 m 凑出 
	{
		return 1;
	}
	
	return 0;
}

int sol()
{
	int l = 0;
	int r = 0;
	int mid = 0;
	
	int res = 0;
	
	l = 1; // 至少一个 
	r = n; // 顶多 全算上 n 个 
	
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		
		if(check(mid) == 1)
		{
			res = max(res, mid);
			
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	return res;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int res = 0;
	int tmp = 0;
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n, cmp); // 升序排序 
	
	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
		
		// 目标值 a[i] 最多凑 多少个？
		
		tar_i = i;
		
		tmp = sol(); 
		
		res = max(res, tmp);
	}
	
	cout << res << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
