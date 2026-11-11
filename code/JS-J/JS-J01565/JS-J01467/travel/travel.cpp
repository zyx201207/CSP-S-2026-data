#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a1, a2, b1, b2;
    char a, b;
    cin >> a1 >> a2 >> a >> b1 >> b2 >> b;
    if(a1 != b1)
    {
        cout << "0000";
        return 0;
    }
    if(a2 != b2)
    {
        cout << "1000";
        return 0;
    }
    if((a <= 'C' && b > 'C') || (a > 'C' && b <= 'C'))
    {
        cout << "1100";
        return 0;
    }
    if((char(a + 1) != b) && char(b + 1) != a)
    {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}
/*
cin1:

cout1:

cin2:

cout2:

cin3:

cout3:

cin4:

cout4:

cin5:

cout5:

*/
