#include "bits/stdc++.h"
using namespace std;
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);

    int n , m;
    int a[200010];

    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    int num = 0;
    int maxx = 0;
    for(int i = 1 ; i <= n ; i++)
    {

        for(int j = 1 ; j <= m ; j++) num &= a[i];
        if(maxx < num) maxx = num;
    }

    cout << num;

    return 0;
}
