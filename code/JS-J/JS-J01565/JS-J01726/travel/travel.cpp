#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

string a, b, c, d;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);  
    cin >> a >> b >> c >> d;
    cout << (a == c);
    int n = (b[0] - '0') * 10 + (b[1] - '0');
    int m = (d[0] - '0') * 10 + (d[1] - '0');
    cout << (n == m && a == c);
    bool f = ((n == m && a == c) && (!((b[2] <= 'C') ^ (d[2] <= 'C'))));
    cout << f << (f && (abs(b[2] - d[2]) == 1)) << endl;

    return 0;
}