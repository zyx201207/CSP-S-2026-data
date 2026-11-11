#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin >> n >> m;
    int a[105];
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    int maxx = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] > maxx)
        {
            maxx = a[i];
        }
    }
    cout << maxx;
    return 0;
}
