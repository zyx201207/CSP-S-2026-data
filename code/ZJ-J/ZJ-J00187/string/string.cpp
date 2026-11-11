#include<bits/stdc++.h>
using namespace std;

vector<pair<long long, char>> vec;
int n;
long long ans = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	if(n == 0 or n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	vec.resize(n);
	for(int i = 0; i < n; ++ i)
	{
		cin >> vec[i].first >> vec[i].second;
		if(i != 0)
		{
			if(vec[i].second == vec[i-1].second)
			{
				vec[i-1].first += vec[i].first;
				-- i;
				-- n;
			}
		}
	}
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	int l = 0, r = n - 1;
	while(l <= r)
	{
		if(vec[l].second == vec[r].second)
		{
			if(vec[l].first > vec[r].first)
			{
				vec[l].first -= vec[r].first;
				-- r;
			}
			else if(vec[l].first < vec[r].first)
			{
				vec[r].first -= vec[l].first;
				++ l;
			}
			else
			{
				++ l, -- r;
			}
		}
		else
		{
			if(vec[l].first > vec[r].first)
			{
				vec[l].first -= vec[r].first;
				ans += vec[r].first;
				-- r;
			}
			else if(vec[l].first < vec[r].first)
			{
				vec[r].first -= vec[l].first;
				ans += vec[l].first;
				++ l;
			}
			else
			{
				ans += vec[l].first;
				++ l, -- r;
			}
		}
	}
	cout << ans << endl;
}