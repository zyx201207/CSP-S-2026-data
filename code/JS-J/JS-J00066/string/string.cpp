#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt = 0;
struct Abc
{
    long long a;
    char b;
}a[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].a >> a[i].b;
    }
    int l = 1, r = n;
    while(l < r)
    {
        bool i = (a[r].b != a[l].b);
        if(a[l].a < a[r].a)
        {
            a[r].a -= a[l].a;
            if(i) cnt += a[l].a;
            l++;
        }
        else if(a[l].a > a[r].a)
        {
            a[l].a -= a[r].a;
            if(i) cnt += a[r].a;
            r--;
        }
        else
        {
            if(i) cnt += a[l].a;
            l++;
            r--;
        }
    }
    cout << cnt;
    return 0;
}
