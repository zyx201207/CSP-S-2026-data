#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define y1 qht_yjx
#define hash ZhaoAk
#define maxn 500005
#define I ios :: sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);
#define rep(i ,l ,r) for (int i = l ;i <= r ;i ++)
#define per(i ,l ,r) for (int i = r ;i >= l ;i --)
#define pb push_back
#define vt vector
#define pii pair <int ,int>


using namespace std;


void chkmxm (int &x ,int y)
{
	x = max (x ,y);
	return ;
}


int n ,m ,a[maxn] ,pre[maxn];


signed main ()
{
	I AK CSP
	
	freopen ("crystal.in" ,"r" ,stdin);
	freopen ("crystal.out" ,"w" ,stdout);
	
	cin >> n >> m;
	rep (i ,1 ,n)
		cin >> a[i];
	
	sort (a + 1 ,a + n + 1 ,less <int> ());
	
	rep (i ,1 ,n)
		pre[i] = pre[i - 1] + a[i];
//	rep (i ,1 ,n)
//		cout << a[i] << " ";
//	cout << endl;
//	rep (i ,1 ,n)
//		cout << pre[i] << " ";
//	cout << endl;
	
	int ans = 0;
	rep (i ,1 ,n)
	{
		int pos = i;
		per (j ,0 ,20)
			if (pos - (1ll << j) > 0 && a[i] * (i - pos + 1 + (1ll << j)) - (pre[i] - pre[pos - (1ll << j) - 1]) <= m)
				pos -= (1ll << j);
//		cout << i << " " << pos << " " << a[i] * (i - pos + 1) - (pre[i] - pre[pos - 1]) << endl;
		chkmxm (ans ,i - pos + 1);
	}
	
	cout << ans << endl;
	
	return !!!!! ("ShZhao" && "SHzhao");
}
