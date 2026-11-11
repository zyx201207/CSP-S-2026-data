#include <bits/stdc++.h>

using namespace std;
char c[10] = {'A', 'B', 'C', 'E', 'D', 'F'};
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, c1, s2, c2;
    cin >> s1 >> c1 >> s2 >> c2;
    if (s1 != s2)
    {
        cout << "0000\n";
        return 0;
    }
    cout << "1";
    if (c1[0] == c2[0] && c1[1] == c2[1]) cout << "1";
    else
    {
        cout << "000\n";
        return 0;
    }
    if ((c1[2] == 'A' && (c2[2] == 'B' || c2[2] == 'C')) || (c1[2] == 'B' && (c2[2] == 'A' || c2[2] == 'C')) || (c1[2] == 'C' && (c2[2] == 'B' || c2[2] == 'A')) || (c1[2] == 'D' && c2[2] == 'F') || (c1[2] == 'F' && c2[2] == 'D')) cout << "1";
    else
    {
        cout << "00\n";
        return 0;
    }
    for (int i = 0; i <= 5; ++i)
    {
    	if ((c1[2] == c[i] && c2[2] == c[i + 1]) || (c2[2] == c[i] && c1[2] == c[i + 1]))
    	{
    	    cout << "1\n";
    	    return 0;
    	}
    }
    cout << "0\n";
    return 0;
}
