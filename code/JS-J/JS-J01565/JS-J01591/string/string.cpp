#include <bits/stdc++.h>
using namespace std;
long long n , ans;
struct node
{
    long long a;
    char c;
}a[200005];
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i].a >> a[i].c;
    }
    for(int i = 1 , j = n;i < j;)
    {
        int k = 1;
        if(a[i].c == a[j].c)
        {
            k = 0;
        }
        if(a[i].a > a[j].a)
        {
            a[i].a -= a[j].a;
            ans += k * a[j].a;
            j --;
        }
        else if(a[i].a < a[j].a)
        {
            a[j].a -= a[i].a;
            ans += k * a[i].a;
            i ++;
        }
        else
        {
            ans += k * a[i].a;
            i ++;
            j --;
        }
    }
    cout << ans;
    return 0;
}
