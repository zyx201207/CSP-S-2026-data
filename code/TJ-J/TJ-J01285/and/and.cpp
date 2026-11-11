#include<bits/stdc++.h>
using namespace std;
const int N = 20005;
int n,m;
long long q[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;++i)
		cin >> q[i];
	sort(q + 1,q + n + 1);
	if (m == 1)
	{
		cout << q[n];
		return 0;
	}
	return 0;
 } 
