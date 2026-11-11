#include <bits/stdc++.h>
using namespace std;
int m,n,a[n];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> m >> n >> a[n];
    int cnt = 0;
    for(int i = 1;i <= s.length()-1;i++)
    {
        for(int j = 1;j <= s.length()-1;j++)
        {
            if(a[n] == 0)
                cout << a[n] + 1;
            else if(a[n] == 1)
                cout << a[n] - 1;
            else
                cout << a[n] + n + m;
        }
        cnt++;
        cout << a[n];
    }
    cout << cnt;
    return 0;
}
