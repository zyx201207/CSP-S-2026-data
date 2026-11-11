#include<bits/stdc++.h>
using namespace std;
int a[20010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,b = 0;
    cin >> m >> n;
    int l = n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    b=a[n];
    while(l > 0 && l <= n)
    {
        if(a[l] < b)
        {
            m--;
        }
        if(m == 1)
        {
            break;
        }
        l--;
    }
    cout << a[l];
    return 0;
}
