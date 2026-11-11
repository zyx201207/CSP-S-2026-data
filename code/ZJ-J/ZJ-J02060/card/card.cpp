#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
map<int, int> ans;

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	bool checkA = true;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
		if(a[i] < a[i - 1]) checkA = false;
	}
	if(checkA)
	{
		map<int, int> w_a;
		for(int i = 1; i <= n; i ++)
			w_a[a[i]] = max(w_a[a[i]], i);
			
		for(int i = 1; i <= m; i ++)
			cout << w_a[i] << " ";
			
		cout << endl;
		return 0; 
	}
	stack<int> stk;
	for(int i = 1; i <= n; i ++)
	{
		map<int, int> mp;
		//cout << i << ":";
		for(int j = i; j <= n; j ++) // 每局跳过 i - 1张
		{
			//cout << j << " ";
			if(mp[a[j]] && !stk.empty()) //如果有了
				while(stk.top() != a[j] && !stk.empty()) 
				{
					mp[stk.top()] --;
					stk.pop();
				}
			else 
			{
				mp[a[j]] ++;
				stk.push(a[j]); 
			}
		}	
		//cout << endl;
		while(!stk.empty())
		{
			ans[stk.top()] ++;
			stk.pop();
		}
	}
	
	for(int i = 1; i <= m; i ++)
		printf("%lld ", ans[i]);
	puts("");
	return 0;
}
