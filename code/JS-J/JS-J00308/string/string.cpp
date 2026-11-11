#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l,s;
struct c
{
    long long x;
    char y;
}cx[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    m = n;
    while(n--)
    {
        cin >> cx[m-n-1].x >> cx[m-n-1].y;
        l += cx[m-n-1].x;
    }
    l /= 2;
    long long i = 0,j = m-1,midd = 0;
    while (i != j)
    {
        if (cx[i].y != cx[j].y)
        {
            midd = min(cx[i].x,cx[j].x);
            s += midd;
        }
        if (cx[i].x > cx[j].x)
        {
            cx[i].x -= cx[j].x;
            j -= 1;
        }
        else if (cx[i].x < cx[j].x)
        {
            cx[j].x -= cx[i].x;
            i += 1;
        }
        else if (cx[i].x == cx[j].x)
        {
            i += 1;
            j -= 1;
        }
    }
    cout << s;
    return 0;
}
