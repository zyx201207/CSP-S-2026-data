#include"bits/stdc++.h"
#define int long long 
using namespace std;
const int MAX = 500005;
int a[MAX];
int t[MAX];
int pd[MAX];
int gxr[MAX];
int ps, n, m, ps_ofpd;
int found(int num)
{
	for ( int i = 1 ; i <= ps ; i ++ )
	{
		if ( pd[i] == num ) {return i;}
	}
}
bool inpd(int num)
{
	for ( int i = 0 ; i <= ps ; i ++ )
	{
		if ( pd[i] == num ) { return true; }
	}
	return false;
}
void cut(int i)
{
	for ( int j = 1 ; j <= ps ; j ++ )
	{
		if ( pd[j] > i ) { pd[j] = 0; ps--; }	
	}
}

signed main()
{
	freopen("card.in", r, stdin)
	freopen("card.out", w, stdout)
	n, m; cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ ) { cin >> a[i]; }
	ps_ofpd = 1;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		ps = 0;
		memset(pd, 0,sizeof(pd));
		memset(t, 0,sizeof(t));
		for ( int j = ps_ofpd ; j <= n ; j ++ )
		{
			if ( t[a[j]] == 0 ) 
			{
				t[a[j]] ++;
				ps ++;
				pd[ps] = a[j];
			}
			else 
			{
				t[a[j]] = 0;
				cut(found(a[j]));
				pd[ps] = a[j];
			}
		}
	
		for (int i = 1; i <= ps ; i ++)
		{
			cout << pd[i];
		}
		cout << endl;
		ps_ofpd ++;
		for ( int j = 1 ; j <= m ; j ++ )
		{
			if ( inpd(j) ) { gxr[j] ++; }
//			cout << gxr[j] << ' ';		
		}
//		cout << endl;
	}
	for ( int i = 1 ; i <= m ; i ++ ) { cout << gxr[i] << ' '; }
	return 0;
}
