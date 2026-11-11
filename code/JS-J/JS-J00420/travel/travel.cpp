#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen(travel.in,"r",stdin);
    freopen(travel.out,"w", stdout);
    string s1, s2;
    string t1, t2;
    cin >> s1 >> t1;
    cin >> s2 >> t2;
    if(s1 == s2)  cout << 1;
    else cout << 0;
    if(t1[0] == t2[0] && t1[1] == t2[1])  cout << 1;
    else cout << 0;
    if(abs(t1[2] - t2[2]) <= 4)  cout << 1;
    else cout << 0;
    if(abs(t1[2] - t2[2]) <= 1)
    {
        if(t1[2] != 'C' && t2[2] != 'D')
        {
            if(t1[2] != 'D' && t2[2] != 'C')  cout << 1;
            else cout << 0;
        }
        else  cout << 0;
    }
    else cout << 0;
    return 0;
}
