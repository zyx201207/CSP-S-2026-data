#include<bits/stdc++.h>
using namespace std;

int n , m;
int k , c[51000];
bool flag = 1;

struct Node
{
    int num , id;
}a[5100] , b[5100];

int fun(int x)
{
    int l = 1 , r = k;
    while(l <= r)
    {
        int mid = (l + k) / 2;
        if(b[mid].num < x)
            l = mid + 1;
        else if(b[mid].num > x)
            r = mid - 1;
        else if(b[mid].num == x)
            return mid;
    }
    return -1;
}

int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].num;
        a[i].id = i;
        if(a[i].num > a[i - 1].num) flag = 0;
    }
    a[n + 1] = 2147483647
    if(flag)
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i].num != a[i + 1].num) cout << i << " ";
        }
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        k = 0;
        for(int j = i; j <= n; j++)
        {
            int p = fun(a[j].num);
            if(p == -1)
            {
                k++;
            }
            if(p != -1)
            {
                k = p;
            }
            b[k] = a[j];
        }
        for(int j = 1; j <= k; j++)
        {
            c[b[j].num]++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << c[i] << " ";
    }
}
