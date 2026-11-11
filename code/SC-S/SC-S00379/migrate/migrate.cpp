#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define y1 qht_yjx
#define hash ZhaoAk
#define maxn 2000005
#define I ios :: sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);
#define rep(i ,l ,r) for (int i = l ;i <= r ;i ++)
#define per(i ,l ,r) for (int i = r ;i >= l ;i --)
#define pb push_back
#define vt vector
#define pii pair <int ,int>


using namespace std;


int n ,d ,a[maxn] ,f[maxn] ,g[maxn] ,pre[maxn] ,pos[maxn];


void solvedengcha ()
{
	cin >> n >> d;
	rep (i ,1 ,n)
		cin >> a[i];
	
	if (n == 1)
	{
		cout << 0 << endl;
		return ;
	}
	
	int dt = a[2] - a[1];
	int k = d / dt;
	if (k < 2)
	{
		cout << 0 << endl;
		return ;
	}
	
	cout << max (0ll ,n - (k << 1) + 1) << endl;
	
	return ;
}


void solvequanda ()
{
	cin >> n >> d;
	rep (i ,1 ,n)
		cin >> a[i];
	
	if (n == 1)
	{
		cout << 0 << endl;
		return ;
	}
	
	vt <int> vec;
	rep (i ,1 ,n)
		if (a[n] - a[i] <= d && a[i] - a[1] <= d)
			vec.pb (i);
	
	if (vec.size () != 2)
	{
		cout << 0 << endl;
		return ;
	}
	
	cout << (vec[0] - 1) * (n - vec[1]) << endl;
	
	return ;
}


void naive ()
{
	cin >> n >> d;
	rep (i ,1 ,n)
		cin >> a[i];
//	rep (i ,1 ,n)
//		cout << a[i] << " ";
//	cout << endl;
	
	if (n == 1)
	{
		cout << 0 << endl;
		return ;
	}
	
	int ans = 0;
//	cout << n << endl;
	rep (i ,1 ,n)
	{
//		cout << "----" << i << "----" << endl;
		rep (j ,1 ,n)
			f[j] = g[j] = pre[j] = 0;
		g[i] = pre[i] = 1;
		int ps = i ,cur = i;
		rep (j ,i + 1 ,n)
		{
//			cout << j << " " << ps << endl;
			while (a[j] - a[ps] > d)
				ps ++;
//			cout << a[j] - a[ps] << endl;
			if (cur < ps)
				cur = ps;
			while (cur < j - 1 && f[cur + 1] == f[cur])
				cur ++;
			if (ps == j)
			{
//				cout << ps << " " << j << endl;
//				cout << ans << endl;
//				cout << "zaotui" << endl;
				break ;
			}
			f[j] = f[ps] + 1;
			g[j] = pre[cur] - pre[ps - 1];
			pre[j] = pre[j - 1] + g[j];
		}
		rep (j ,i ,n)
			ans += (int) (g[j] == 2);
//		rep (j ,i ,n)
//			cout << g[j] << " ";
//		cout << endl;
	}
	
	cout << ans << endl;
	
	return ;
}


signed main ()
{
	I AK CSP
	
	freopen ("migrate.in" ,"r" ,stdin);
	freopen ("migrate.out" ,"w" ,stdout);

	int c ,T;
	cin >> c >> T;
	
	while (T --)
	{
//		cout << "#######" << T << endl;
		if (c == 11 || c == 12)
			solvedengcha ();
		else if (c == 13 || c == 14)
			solvequanda ();
		else
			naive ();
	}

	return !!!!! ("ShZhao" && "SHzhao");
}

