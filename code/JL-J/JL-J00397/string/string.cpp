#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n;
string s;
struct node
{
    long long y;
    char d;
}t[N];
struct Node
{
    long long x;
    char c;
}a[N];
long long ans,cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> t[i].y >> t[i].d;
    }
    for(int i = 1;i <= n;i ++)
    {
        int k = 1;
        while(t[i].d == t[i+k].d)
        {
            t[i].y += t[i+k].y;
            t[i+k].y = 0;
            k ++;
        }
        i += k;
    }
    int k = 1;
    for(int i = 1;i <= n;i ++)
    {
        if(t[i].y != 0)
        {
            a[k].x = t[i].y;
            a[k].c = t[i].d;
            k ++;
        }
    }
    k --;
    int i = 1,j = k;
    while(i < j)
    {
        if(a[i].c != a[j].c)
        {
            if(a[i].c != a[j].c) ans += min(a[i].x,a[j].x);
            if(a[i].x >= a[j].x)
            {
                a[i].x -= a[j].x;
                a[j].x = 0;
            }
            else
            {
                a[j].x -= a[i].x;
                a[i].x = 0;
            }
        }
        else if(a[i].x != a[j].x)
        {
            if(a[i].x >= a[j].x)
            {
                a[i].x -= a[j].x;
                a[j].x = 0;
            }
            else
            {
                a[j].x -= a[i].x;
                a[i].x = 0;
            }
        }
        else
        {
            a[i].x = 0;
            a[j].x = 0;
        }
        if(a[i].x == 0) i ++;
        if(a[j].x == 0) j --;
    }
    cout << ans;
    return 0;
}
