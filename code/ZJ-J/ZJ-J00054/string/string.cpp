#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, m;
    string s, s1;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> m;
        cin >> s1;
        for(int j=0; j<m; j++)
            s += s1;
    }
    m = 0;
    for(int i=0; i*2<=s.size(); i++)
        if(s[i]!=s[s.size()-1-i])
            m++;
    cout << m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
