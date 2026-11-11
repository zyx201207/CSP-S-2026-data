//liuyixi xi an shi han guang zhong xue SN-J00686
#include<bits/stdc++.h>
using namespace std;
int vis[1010100];
int main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int ans[1010000];
	int a[1010100];
	int n,m;
	cin >> n >> m;
	deque<int> a2;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i < m; i++)
	{
		cout << i << " ";
	}
	
	return 0;
}
