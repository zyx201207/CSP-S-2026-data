#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num = 0;
    cin >> n;
    int s;
    for ( int i = 1;i <= n;i++)
    {
        cin >> s;
        if(s != -s)
        {
            num++;
        }
    }
    cout << num;
    return 0;
}
