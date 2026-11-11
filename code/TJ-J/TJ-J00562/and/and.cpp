#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+7;
//priority_queue<int,vector<int>,greater<int> > q;
int a[maxn];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[n-m+1];
	return 0;
}
