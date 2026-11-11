#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
const int M = 1e7;
LL a[N];
LL s[M] = {0};
int n,m;
LL ans,mx = 0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		s[a[i]] ++;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(s[i] == 1) 
		{
			ans = (a[i] & a[i]); 
			mx = max(mx,ans);
		}
	}
	cout << mx;
	return 0;
}
