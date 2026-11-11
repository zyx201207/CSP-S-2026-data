#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    long long s1, s1_n, s2, s2_n;
    string s1_m, s2_m, ans;
    cin >> s1 >> s1_n >> s1_m >> s2 >> s2_n >> s2_m;
    if (s1 != s2)
    {
        cout << "0000" << "\n";
        return 0;
    }
    else
    {
        ans = "1";
        if (s1_n != s2_n)
        {
            cout << "1000" << "\n";
            return 0;
        }
        else
        {
            ans = "11";
            if (s1_m == "A" && s2_m == "B")
            {
                cout << "1111" << "\n";
            }
            else if (s1_m == "B" && s2_m == "A")
            {
                cout << "1111" << "\n";
            }
            else if (s1_m == "A" && s2_m == "C")
            {
                cout << "1110" << "\n";
            }
            else if (s1_m == "C" && s2_m == "A")
            {
                cout << "1110" << "\n";
            }
            else if (s1_m == "B" && s2_m == "C")
            {
                cout << "1111" << "\n";
            }
            else if (s1_m == "C" && s2_m == "B")
            {
                cout << "1111" << "\n";
            }
            else if (s1_m == "D" && s2_m == "F")
            {
                cout << "1111" << "\n";
            }
            else if (s1_m == "F" && s2_m == "D")
            {
                cout << "1111" << "\n";
            }
            else
            {
                cout << "1100" << "\n";
                return 0;
            }
        }
    }
    return 0;
}
