#include<iostream>
#include<deque>
#include<cmath>
using namespace std;

deque<pair<long long, char>> s;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long t, t1, t2, tmp, t3, size, ans = 0;
	char c1, c2;
	cin>>t;
	cin>>t1>>c1;
	while(--t)
	{
		cin>>t2>>c2;
		if(c2 == c1)
		{
			t1 += t2;
			//cout << "}";
		}
		else
		{
			s.push_back(make_pair(t1, c1));
			c1 = c2;
			t1 = t2;
			//cout << "{";
		}
	}
	s.push_back(make_pair(t1, c1));
	size = s.size();
	//cout << '\n' << size << '\n';
	if(size == 1)
	{
		cout << 0;
		return 0;
	}
	if(size == 2)
	{
		if(s.front().second == s.back().second)
		{
			cout << 0;
		}
		else
		{
			cout << min(s.front().first, s.back().first);
		}
		return 0;
	}
	while(!s.empty())
	{
		//cout << '\n' << s.empty() << '\n';
		if(s.size() == 1)
		{
			break;
		}
		t1 = s.front().first;
		c1 = s.front().second;
		t2 = s.back().first;
		c2 = s.back().second;
		t3 = 0;
		s.pop_front();
		s.pop_back();
		tmp = abs(t1 - t2);
		t = tmp;
		if(c1 == c2)
		{
			if(t1 < t2)
			{
				while(tmp && !s.empty())
				{
					t3 += s.front().first;
					if(s.front().first <= tmp)
					{
						tmp -= s.front().first;
						s.pop_front();
					}
					else
					{
						s.front().first -= tmp;
						//cout << "*^";
						break;
					}
					//cout << "*";
				}
            }
            else
            {
				while(tmp && !s.empty())
				{
					t3 += s.back().first;
					if(s.back().first <= tmp)
					{
						tmp -= s.back().first;
						s.pop_back();
					}
					else
					{
						s.back().first -= tmp;
						//cout << "%^";
						break;
					}
					//cout << "%";
				}
			}
			ans += min(t, t3);
		}
		else
		{
			if(t1 < t2)
			{
				while(tmp && !s.empty())
				{
					t3 += s.front().first;
					if(s.front().first <= tmp)
					{
						tmp -= s.front().first;
						s.pop_front();
					}
					else
					{
						s.front().first -= tmp;
						//cout << ")*";
						break;
					}
					//cout << ")";
				}
				ans += min(t2, t3);
			}
			else
			{
				while(tmp && !s.empty())
				{
					t3 += s.back().first;
					if(s.back().first <= tmp)
					{
						tmp -= s.back().first;
						s.pop_back();
					}
					else
					{
						s.back().first -= tmp;
						//cout << "(*";
						break;
					}
					//cout << "(";
				}
				ans += min(t1, t3);
			}
		}
		//cout << '\n';
	}
	cout << ans;
	return 0;
}


