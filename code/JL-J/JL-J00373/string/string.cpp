#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.cpp", "r", stdin);
    freopen("string.cpp", "w", stdout);
    long long n;
    string s;
    cin >> n;
    long long a[n + 5];

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> s[i];

        if(s[i] - '0' == s[i + 1] - '0')
        {
            cout << 0;
            return 0;
        }
    }

    if(n == 1) cout << 0;

    fclose(stdin);
    fclose(stdout);

    return 0;
}


