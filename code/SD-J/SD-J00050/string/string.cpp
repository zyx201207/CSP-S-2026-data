#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 10;
int n;
struct node 
{
	int num;
	char c; 
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].num >> a[i].c;
	}
	int l = 1, r = n;
	int ans = 0;
	while(l < r) 
	{
		if(a[l].c == a[r].c)
		{
			if(a[l].num == a[r].num) l++,r--;
			else if(a[l].num > a[r].num) a[l].num -= a[r].num,r--;
			else a[r].num -= a[l].num,l++;
		}else 
		{
			if(a[l].num == a[r].num) ans += a[l].num,l++,r--;
 			else if(a[l].num > a[r].num) a[l].num -= a[r].num, ans += a[r].num,r--; 
			else a[r].num -= a[l].num,ans += a[l].num,l++;
		}
	}
	cout << ans << endl; 
	return 0;
}
