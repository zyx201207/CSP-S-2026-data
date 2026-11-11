#include <bits/stdc++.h>
using namespace std;
map < char, int > mp;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    mp['A'] = mp['B'] = mp['C'] = 1, mp['D'] = mp['F'] = 2;
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if (s1 == s3)
        printf("1");
    else 
    {
        printf("0000");
        return 0;
    }
    if (s2[0] == s4[0] && s2[1] == s4[1]) printf("1");
    else
    {
        printf("000");
        return 0;
    }
    if (mp[s2[2]] == mp[s4[2]]) printf("1");
    else
    {
        printf("00");
        return 0;
    }
    if ((s2[2] == 'A' && s4[2] == 'C') || (s2[2] == 'C' && s4[2] == 'A'))
    {
        printf("0");
        return 0;
    }
    else printf("1");
    return 0;
}
