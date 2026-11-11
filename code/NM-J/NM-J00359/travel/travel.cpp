#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == s1 || c2 "A" == s2"B" || c2"B" == s2"C" || c2"E" == s2"F")
        cout << 1 ;
    else
        cout << 0;
    return 0;
}
