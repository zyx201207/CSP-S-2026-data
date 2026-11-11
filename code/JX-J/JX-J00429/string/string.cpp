#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int a =0;
    int b =0;
    char c;
    char d;
    int ans =0;
    cin >> a >> c >> b >>d;
    if(c==d)
    {
        cout << 0;
    }
    else if(a>b)
    {

        cout << b;
    }
    else if(b>a)
    {
        cout << a;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
