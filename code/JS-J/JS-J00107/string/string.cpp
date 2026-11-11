#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
char c[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
    }
    int ret = 0;
    int pos1 = 1,pos2 = n;
    while(pos1 <= pos2)
    {
        int mi = min(a[pos1],a[pos2]);
        if(c[pos1] != c[pos2])
        {
            ret += mi;
        }
        if(a[pos1] > a[pos2])
        {
            a[pos1] -= a[pos2];
            pos2--;
        }
        else
        {
            a[pos2] -= a[pos1];
            pos1++;
        }
    }
    cout << ret;
    return 0;
}
