#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned lli
#define f(i, a, b) for(lli i = a; i <= b; i++)

const ulli MAX_SIZE = 5e5 + 5;

map<lli, lli> answers; // answers[i]: 结束时留有点数为 i 的牌的次数 
lli a[MAX_SIZE];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	lli n, m;
	
	cin >> n >> m;
	f(i, 1, n)
	{
		cin >> a[i];
	}
	
	f(i, 1, n) // 模拟 n 局游戏 
	{
		vector<lli> st(MAX_SIZE);
		lli top = -1; 
		
		f(j, i, n) // 模拟出牌 
		{
			lli p = -1;
			
			f(k, 0, top) // 找是否已有这张牌 
			{
				if(st[k] == a[j])
				{
					p = k;
					break;
				}
			}
			
			if(p == -1) // 没有
			{
				st[++top] = a[j];
			}
			else // 已有
			{
				top = p;
			}
		}
		
		f(j, 0, top) // 统计
		{
			answers[st[j]]++;
		}
	}
	
	f(i, 1, m)
	{
		cout << answers[i] << " ";
	}
	
	return 0;
}
