#include<bits/stdc++.h>

#define int long long

using namespace std;
array<int , 2000100> lim , pos;

deque<pair<int , int> > q;

int valid = 0 , ans = 0 , flag = 1 , sum = 1;

void update(int l , int r)
{
	if(q.empty())
	{
		valid = 0 , flag = 0;
		q.push_back({l , r});
		return;
	}
	
	if(q.front().first <= l && q.front().second >= r) return;
	
	if(q.front().second < l)
	{
		while(!q.empty()) q.pop_front();
		q.push_back({l , r});
		valid = 0 , flag = 0;
		return;
	}
	
	
	while(q.size() >= 2)
	{
		auto it1 = q.front();
		q.pop_front();
		auto it2 = q.front();
		q.pop_front();
		
		if(it2.second >= l)
		{
			if(it1.second - l == 1) ans += (l - it1.first) * (r - it1.second);
			
			if(it2.second == it1.first + 1) -- valid;
			if(it2.second > it1.first + 1) -- flag;
			q.push_front(it2);
			
			continue;
		}
		
		q.push_front(it2) , q.push_front(it1);
		
		break;
	}
//	cout << l << ' ' << r << ' ' << q.size() << endl;
	
	if(q.front().second == l)
	{
		auto it = q.front();
		q.pop_front();
		q.push_front({it.first , r});
	}
	else if(q.front().second == l + 1)
	{
		++ valid , sum = (l - q.front().first) * (r - q.front().second);
		q.push_front({l , r});
	}
	else
	{
		++ flag;	
		q.push_front({l , r});
	}
	
	l = q.front().first , r = q.front().second;
	
//	cout << "* " << q.front().second << ' ' << l + 1 << endl;
//	cout << valid << ' ' << flag << endl;
//	cout << l << ' ' << r << ' ' << q.size() << endl;
	
	if(valid == 0) return;
	
	while(!q.empty() && valid > 1)
	{
		auto it1 = q.back();
		q.pop_back();
		
		if(it1.second == q.back().first + 1) -- valid;
		if(it1.second > q.back().first + 1) -- flag;
	}
	
	if(flag == 0 && valid == 1) ans += sum;
	
	return;
}

signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int c = 0 , T = 0;
	
	cin >> c >> T;
	
	while(T --)
	{
		ans = 0;
		
		while(!q.empty()) q.pop_front();
		
		valid = 0 , flag = 0;
		
		int n = 0 , d = 0;
		
		cin >> n >> d;
		
		for(int i = 1;i <= n;++ i) cin >> pos[i];
		
		for(int i = 1;i <= n;++ i)
		{
			lim[i] = upper_bound(pos.data() + 1 , pos.data() + n + 1 , pos[i] + d) - pos.data() - 1;
		}
		
		for(int i = 1;i <= n;++ i) update(i , lim[i]);
		
		cout << ans << '\n';
	}
	
	cout << endl;
	
	return 0;
}

/*

0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000






*/