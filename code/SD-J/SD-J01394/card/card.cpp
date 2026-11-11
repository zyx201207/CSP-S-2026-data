#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100, M = 3e5 + 100;
int a[N], b[N], n, m, num[N];
//stack<int> s;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(b, 0, sizeof(b));
	memset(num, 0, sizeof(num));
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		num[i] = num[i - 1] + b[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cout << num[i] << ' ';
	}
//	for(int i = n; i >= 1; i--)
//	{
//		if(b[a[i]] == 1)
//		{
//			while(1)
//			{
//				if(s.top() == a[i])
//				{
//					break;
//					num[s.top()] -= i;
//				}
//				else
//				{
//					num[s.top()] -= i;
//					b[s.top()] = 0;
//					s.pop();
//				} 
//			}
//		}
//		else
//		{
//			s.push(a[i]);
//			num[s.top()] += i;
//			b[a[i]] = 1;
//		}
//	}
//	for(int i = 1; i <= m; i++)cout << num[i] << ' ';
	return 0;
}

