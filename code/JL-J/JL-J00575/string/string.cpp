#include <bits/stdc++.h>
using namespace std;

int n , m , cnt = 1, ans, aa = 1;
char a[500005] , b[500005];
int main()
{
    //freopen("string.in","r",stdout);
    //freopen("string.out","w",stdout);
    cin >>n ;
    for (int i = 1; i <= n; i++)
    {
        int xx ;
        char yy;
        cin >> xx >> yy ;
        for (int j = 1; j <= xx; j++)
        {
            a[cnt++] = yy ;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        //for (int j = 1; j <= n; j++)
        //{
            b[aa] = a[i] ;
            aa++ ;
        //}
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i]) ans ++;
    }
    cout << ans ;
    return 0 ;
}
