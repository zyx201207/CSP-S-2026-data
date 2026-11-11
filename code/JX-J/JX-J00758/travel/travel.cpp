#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll c1, c2; // che xiang
    ll s1, s2; // pai
    char a, b; // zuo wei hao
    cin >> c1 >> s1 >> a >> c2 >> s2 >> b;

    ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;

    if(c1 == c2)
    {
        t1 = 1;
    }
    else
    {
        cout << t1 << t2 << t3 << t4 << "\n";
        return 0;
    }

    if(s1 == s2)
    {
        t2 = 1;
    }
    else
    {
        cout << t1 << t2 << t3 << t4 << "\n";
        return 0;
    }
    if(a == 'A' || a == 'B' || a == 'C' && b == 'A' || b == 'B' || b == 'C')
    {
        t3 = 1;
    }
    else if(a == 'F' || a == 'D' && b == 'D' || b == 'F')
    {
        t3 = 1;
    }
    else
    {
        cout << t1 << t2 << t3 << t4 << "\n";
        return 0;
    }

    ll ac = a - '0', bc = b - '0';
    if(abs(ac - bc) == 1)
    {
        t4 = 1;
    }
    else
    {
        cout << t1 << t2 << t3 << t4 << "\n";
        return 0;
    }

    cout << t1 << t2 << t3 << t4 << "\n";
    return 0;
}
