#include <iostream>
#include <cstdio>
#include <bits/stdc++.h> 
using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

struct Node
{
	int a;
	char c; 
	LL st;
};

int n = 0;

LL len = 0;

Node nums[N];
LL sts[N];

string str;

LL sol_1()
{
	LL res = 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= nums[i].a; j++)
		{
			str += nums[i].c;
		}
	}
	
	for(int i = 0; i < len / 2; i++)
	{
		if(str[i] != str[len - i - 1])
		{
			res++;
		}
	}
	
	return res;
}

LL max_sol()
{
	LL res = 0;
	
	LL l = 0;
	LL r = 0;
	
	LL nxt_l = 0;
	LL nxt_r = 0;
	
	LL nl = 0;
	LL nr = 0;
	
	int idx = 0;
	
	for(int i = 1; i <= n; i++)
	{
		l = nums[i].st;
		r = min(nums[i].st + nums[i].a - 1, (len + 1) / 2);
		
		if(l > len / 2)
		{
			break;
		}
		
		nxt_l = len + 1 - r;
		nxt_r = len + 1 - l;
		
		idx = upper_bound(sts + 1, sts + 1 + n, nxt_l) - sts - 1; 
		
		while(sts[idx] <= nxt_r && idx <= n)
		{
			if(nums[idx].c != nums[i].c)
			{
				nl = sts[idx];
				nr = sts[idx] + nums[idx].a - 1;
				
				res += min(nr, nxt_r) - max(nl, nxt_l) + 1;
			}
			
			idx++;
		}
	}
	
	return res;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	
	LL res = 0;
	
	int max_a = 0;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> nums[i].a >> nums[i].c;
		
		nums[i].st = len + 1;
		sts[i] = nums[i].st;
		
		len += nums[i].a; // ×Ü³¤¶È 
		
		max_a = max(max_a, nums[i].a); 
	}
	
	if(max_a <= 500)
	{
		res = sol_1();
		
		cout << res << endl;
	}
	else
	{
		res = max_sol();
		
		cout << res << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
