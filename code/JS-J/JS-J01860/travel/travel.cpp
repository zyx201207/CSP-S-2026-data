#include <bits/stdc++.h>
using namespace std;

string sa,ca,sb,cb;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> sa >> ca >> sb >> cb;
    if(sa != sb)
    {
        cout << "0000";
        return 0;
    }
    cout << "1";

    long long x = (ca[0]-'0')*10+(ca[1]-'0');
    long long y = (cb[0]-'0')*10+(cb[1]-'0');
    if(x != y)
    {
        cout << "000";
        return 0;
    }
    cout << "1";

    long long n = ca[2]-'A';
    long long m = cb[2]-'A';
    if((n<=2 && m>2) || (m<=2 && n>2))
    {
        cout << "00";
        return 0;
    }
    cout << "1";

    if(abs(n-m) == 1)
    {
        cout << "1";
    }
    else
        cout << "0";
    return 0;
}
