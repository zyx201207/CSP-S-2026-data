#include <bits/stdc++.h>

using namespace std;

string s = "";

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    long long cnt = 0;
	for(int i = 0; i < n; i++)
    {
        int ls;
        cin >> ls;
        string lt;
        cin >> lt;
        while(ls--)
        {
            s += lt;
        }
    }
    long long nn = s.size();
    for(long long i = 0, j = nn - 1; i < nn && j >= 0 && i < j; i++ && j--)
    {
        if(s[i] != s[j])
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
	return 0;
}
