#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a;
string s = "#";
char c;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a >> c;

        for(int i = 1; i <= a; i++)
        {
            s += c;
            s += '#';
       }
    }

    int cnt = 0;
    int m = s.size() / 2;
    for(int i = 1; i <= m; i++)
    {
        char l = s[m - i];
        char r = s[m + i];
        if(l != r)
        {
            cnt++;
            r = l;
        }
    }

    cout << cnt;


    return 0;
}
