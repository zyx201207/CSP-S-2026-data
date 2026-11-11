#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int n = 0;
ll m = 0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	cin >> n >> m;
	ll alist[n] = {};
	
	for (int i = 0;i < n;i++)
	{
		cin >> alist[i]; 
	}
	sort(alist,alist+n);
	
	int output = 1;
	
	int index_on_n = 1;
	ll allvalue = 0;
	ll addition = 0;
	while (true)
	{
		allvalue = alist[index_on_n-1]*index_on_n;
		addition = 0;
		for (int i = 0;i < index_on_n;i++)
		{
			addition += alist[i];
		}
		allvalue -= addition;
		
		if (m < allvalue)
		{
			output = index_on_n - 1;
			break;
		}
		
		index_on_n++;
		if (index_on_n > n)
		{
			break;
		}
	}
	
	cout << output;
}