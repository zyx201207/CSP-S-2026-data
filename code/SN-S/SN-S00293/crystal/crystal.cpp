#include <bits/stdc++.h>
#define _eggy_ using
#define _party_ namespace
#define sf scanf
#define pf printf
_eggy_ _party_ std; _party_ llamn { _party_{

#define ll long long
numeric_limits<int> INT;
numeric_limits<ll> LL;

#if 0
#define for_nm(do_) for (signed kh = 0, yh = 0; kh || yh || (*i != ',' && *i != '\0'); i++) \
{switch(*i){case '(': case '[': case '{': kh++; break; case ')': case ']': case '}': kh--; break; case '\"': yh ^= 1;} do_;}
#define vtmp template<typename Th, typename... Ts>
#define varg Th&& arg, Ts&&... ars
#define putl(c) (isblank(c)?:putc(c,stderr))

void showf(char* i) {cerr << '\n';}
vtmp void showf(char* i, varg)
{
	for_nm(putl(*i)); cerr << " = " << arg << "   ";
	showf(i+1,ars...);
}

vtmp void gnxt(varg) {return arg;} void gnxt(){}
vtmp void Lnxt(char* i, varg);
void shoaf(char* i) {cerr << '\n';}
vtmp void shoaf(char* i, varg)
{
	for_nm(putl(*i)); cerr << ": ";
	signed j, len = gnxt(ars...);
	for (j = 0; j <= len; j++)
		cerr << arg[j] << ' ';
	cerr << '\n'; Lnxt(i+1,ars...);
}vtmp void Lnxt(char* i, varg) {for_nm(); shoaf(i+1,ars...);}

#define show(...) showf(const_cast<char*>(__VA_ARGS__), __VA_ARGS__);
#define shoa(...) shoaf(const_cast<char*>(__VA_ARGS__), __VA_ARGS__);
#else
#define show(...) void(0);
#define shoa(...) void(0);
#endif

int n,i,j,k,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30;

int l;
ll a[500100], m, c;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0); cin >> n >> m; c = m;
	for (i = 1; i <= n; i++) cin >> a[i]; sort(a+1,a+n+1);
	for (i = 2, t10 = l = 1; i <= n; i++)
	{
		if (a[i] - a[i-1] > c) {c = m, l = i; continue;}
		while (c < (a[i] - a[i-1]) * (i-l)) c += a[i-1] - a[l], l++;
		c -= (a[i] - a[i-1]) * (i-l);
		t10 = max(t10,i-l+1);
	}pf("%d",t10);
	return 0;
}
}} signed main() {return llamn::main();}

/*
luogu 1038651 llamn
 5 5
 1 2 4 8 9
14:44 AC 所有大洋里 
*/























