#include<bits/stdc++.h>
using namespace std;

#define int long long



void solve (){
	int n, d;
	cin >> n >> d;
	int x[n + 10], subtask1 = 1, ans = 0;
	queue <pair <int, int> > q;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> x[i];
		if (i >= 3) 
		    if (x[i] - x[i - 1] != x[i - 1] - x[i - 2]) subtask1 = 0;
	}
	
	if (subtask1)
	{
		//score += 8;
		int c = d / (x[2] - x[1]);
		
		for (int i = 1; i <= n; i ++) 
		{
			ans = ans + min(i + 2 * c - 1, n) - min (i + c, n);
		}
		
		cout << ans << endl;
		return ;
	}
	
	
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i + 1; j <= n; j ++)
		{
			int sum = 0, minn = 1e18;
			
			
			while (q.size()) q.pop();
			q.push({i, 1});
			
			while (q.size())
		    {
		    	pair <int, int> t = q.front(); q.pop();
		    	if (x[t.first] == j)
		    	{
		    		int ominn = minn;
		    		minn = min (minn, t.second);
		    		if (ominn != minn) sum = 0;
		    		if(t.second == minn) sum ++;
		    		
		    		continue;
				}
				else if (t.first > j) continue;
				
				for (int k = t.first + 1; k <= n; k ++)
				{
					if (x[k] - x[t.first] <= d) q.push(make_pair(k, t.second + 1));
				}
			} 
			
			if (sum == 2) ans ++;
		}
	}
	cout << ans << endl;
	return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

    int CCF, T;
	cin >> CCF >> T;
	while (T --) solve();
	return 0;
}

/*

请整理迷惑行为打赏的巨佬隐藏我这篇代码的uid以及准考证号，谢谢！ 
I fell in love with xh.

xh I love you. I will die without you.（It's a truth） 
*/ 
