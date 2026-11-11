#include<iostream>
#define int long long
#define AK return
#define CSP 0;
using namespace std;
int a[200005],b[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//fuckccf//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    int r = 0;
    for(int i = 30;i >= 0;i--)
    {
        int c = 0;
        for(int j = 0;j < n;j++)
        {
            if(!b[j] && (a[j]&(1<<i)) != 0)
            {
                c++;
            }
        }
        if(c >= m)
        {
            r += (1 << i);
            for(int j = 0;j < n;j++)
            {
                if(!b[j] && (a[j]&(1<<i)) == 0)
                {
                    b[j] = true;
                }
            }
        }
    }
    cout << r;
    AK CSP
}
