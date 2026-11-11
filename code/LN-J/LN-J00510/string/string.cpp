#include<bits/stdc++.h>
using namespace std;

long long n, ans;

struct node
{
    long long num;
    char c;
}a[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].num >> a[i].c;
    }
    long long l = 1, r = n;
    while(l < r)
    {
        long long minn = min(a[l].num,a[r].num);
        if(a[l].c != a[r].c)
        {
            ans += minn;
        }
        a[l].num -= minn;
        a[r].num -= minn;
        if(a[l].num == 0)
        {
            l++;
        }
        if(a[r].num == 0)
        {
            r--;
        }
    }
    cout << ans;
    return 0;
}
