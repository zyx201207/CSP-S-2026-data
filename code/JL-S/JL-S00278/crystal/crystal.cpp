/*
Believe yourself!
If the code don't run, 99% is your problem!
Believe yourself!!!!!

da jia xie xun huan de shi hou you zhe dian a !
*/

// 5min solved
// zhe me eazy?
// long long is save?
// nevermind, I trust you.

// small sample accepted, but large sample wrong???why???

// cyt sleep at 15:57
// awake at 16:39
// using 42min.

// binaray ans?
// yes.

// solved at 16:22
// i think this is yellow
// cyt is still sleeping.

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;
#define endl '\n'

LL n, m;
//LL tempa[maxn], temp[maxn];
LL a[maxn], pre[maxn], aipoweri[maxn], need[maxn];

void fileread()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
}

void fastio()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
}

void init()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];

	sort(a+1, a+1+n);

	for(LL i = 1 ; i <= n ; i ++)
	{
		pre[i] = a[i] + pre[i-1];
		aipoweri[i] = a[i] * i;
		need[i] = aipoweri[i] - pre[i];
	}
}

void debug()
{

}

bool check(LL i, LL j)
{
	if( ((a[i]*(i-j))-(pre[i]-pre[j])) <= m )
		return true;
	return false;
}

LL fanhui(LL i, LL ans)
{
	LL l = 0, r = i + 1;
	LL innerans = -1;// innerans is j
	while(l < r)
	{
		LL mid = (l+r) / 2;
		if(check(i, mid))
			r = mid, innerans = mid;
		else
			l = mid + 1;
	}
	if(innerans == -1)
		return ans;
	else if(i-innerans > ans)
		return i-innerans;
	return ans;
}

void solve()
{
	LL ans = -1;
	for(LL i = 1 ; i <= n ; i ++)
	{
		if(m >= need[i])
			ans = i;
		else
			ans = fanhui(i, ans);
	}
	if(ans == -1)
		ans = 1;
	cout << ans << endl;
	//debug();
}

signed main()
{
	fastio();
	fileread();
	init();
	solve();
}
