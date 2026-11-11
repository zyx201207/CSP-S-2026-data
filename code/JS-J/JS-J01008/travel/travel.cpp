#include <bits/stdc++.h>
using namespace std;
#ifdef W_DEBUG
#define DOUT(x...) cerr << __FILE__ << ":" << __LINE__ <<":   " << x << endl
#else
#define DOUT(...) void(0)
#endif
using ll = long long;
namespace sub1
{
void solve()
{
    ll a, b, c, d;
    char e, f;
    cin >> a>>b>>e>>c>>d>>f;
    if(a == c)
    {
	cout <<1;
	if(b == d)
	{
	    cout << 1;
	    if(e<= 'C' and f <= 'C')
	    {
		cout << 1;
		if(abs(e - f) == 1)
		{
		    cout << 1;
		}
		else
		{
		    cout << 0;
		}
	    }
	    else if(e >= 'D' and f >= 'D')
	    {
		cout << "11";
	    }
	    else
	    {
		cout << "00";
	    }
	}
	else
	{
	    cout << "000";
	}
    }
    else
    {
	cout << "0000";
    }
}
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    #define W_N "travel"
    freopen(W_N ".in", "r", stdin);
    freopen(W_N ".out", "w", stdout);
    sub1::solve();
} 
