#include<bits/stdc++.h>
using namespace std;
int a1, a2, b1, b2;
char a3, b3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    if(a1 != b1)
    {
        cout << "0000" << endl;
        return 0;
    }
    if(a2 != b2)
    {
        cout << "1000" << endl;
        return 0;
    }
    if((a3 <= 'C' && b3 > 'C') || (a3 > 'C' && b3 <= 'C'))
    {
        cout << "1100" << endl;
        return 0;
    }
    if((a3 == 'C' && b3 == 'A') || (a3 == 'A' && b3 == 'C'))
    {
        cout << "1110" << endl;
        return 0;
    }
    cout << "1111" << endl;
    return 0;
}
