#include<bits/stdc++.h>
using namespace std;

int a , b , c , d , e , g;
int flag;
string x , y;

int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> a >> x >> b >> y;
    if(a == b) cout << '1';
    else
    {
        cout << '0';
        flag = 1;
    }
    c = (x[0] - '0') * 10 + (x[1] - '0');
    d = (y[0] - '0') * 10 + (y[1] - '0');
    if(!flag && c == d) cout << '1';
    else
    {
        cout << '0';
        flag = 1;
    }
    if(x[2] == 'A' || x[2] == 'B' || x[2] == 'C') e = 1;
    if(y[2] == 'A' || y[2] == 'B' || y[2] == 'C') g = 1;
    if(!flag && e == g) cout << '1';
    else
    {
        cout << '0';
        flag = 1;
    }
    if(flag == 1 || abs(x[2] - y[2]) != 1)cout << '0';
    else cout << '1';
    return 0;
}
