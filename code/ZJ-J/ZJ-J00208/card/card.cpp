#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[300005];
queue<int> a;
queue<int> temp;
queue<int> q;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i < n;i++)
	{
		int x;
		cin >> x;
		a.push(x);
	}
	for(int i = 1;i <= n;i++)
	{
		cout << a.head();
		a.pop();
	}
	return 0;
}
