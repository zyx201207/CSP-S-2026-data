//用串的第一个和最后一个如果不一样互相抵消 
#include<iostream>
#include<queue>
using namespace std;

const int N = 2e5 + 5;

struct Node
{
	int a;
	char c;
};

int n;
long long ans = 0;

deque<Node> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int a;
		char c;
		cin >> a >> c;
		que.push_back({a, c});
	}
	
	while(!que.empty())
	{
		Node hd = que.front();
		que.pop_front();
		if(que.empty()) break;
		Node bk = que.back();
		que.pop_back();
		if(hd.c == bk.c)
		{
			if(hd.a > bk.a)
			{
				que.push_front({hd.a - bk.a, hd.c});
			}
			else if(hd.a < bk.a)
			{
				que.push_back({bk.a - hd.a, bk.c});
			}
		}
		else
		{
			if(hd.a > bk.a)
			{
				que.push_front({hd.a - bk.a, hd.c});
				ans += bk.a;
			}
			else if(hd.a < bk.a)
			{
				que.push_back({bk.a - hd.a, bk.c});
				ans += hd.a;
			}
			else
			{
				ans += hd.a;
			}
		}
	}
	
	cout << ans;
	
	return 0;
} 
