#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	vector <int> a;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	sort(a.begin(),a.end());
	cout << a[a.size()-1];
	return 0;
}
