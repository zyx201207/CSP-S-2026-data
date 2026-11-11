#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
int nnnn__max__nnnn = -1e9;
void dfs(vector<int> &a , int t , int m)
{
	if ( t < nnnn__max__nnnn || m == 0 ) 
	{
		nnnn__max__nnnn = max(nnnn__max__nnnn , t);
		return;
	}
	for ( auto &tk : a )
	{
		if ( tk == -1 ) continue;
		int ttk = tk;
		tk = -1;
		dfs(a , t & ttk , m - 1);
		tk = ttk;
	}
	return;
}
int main()
{
	#ifndef DEBUG
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	#else
	freopen("E:\\cspj\\down\\and\\and2.in" , "r" , stdin);
	freopen("E:\\cspj\\down\\and\\and2.out" , "w" , stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n , m;
	cin >> n >> m;
	vector<int> a(n);
	for ( auto & i : a ) cin >> i;
	sort(a.begin() , a.end());
	for ( auto &t : a )
	{
		int tt = t;
		t = -1;
		dfs(a , tt , m);
		t = tt;
	}
	cout << nnnn__max__nnnn;
	return 0;
}
/*
dino 1531!!!
*/