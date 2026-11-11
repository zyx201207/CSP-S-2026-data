#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }
    int l = 1,r = n;
    long long cnt = 0;
    while (l<=r)
    {
        if (a[l]>a[r])
        {
            if (b[l]!=b[r])
            {
                cnt+=a[r];
            }
            a[l]-=a[r];
            a[r] = 0;
            r--;
        }
        else
        {
            if (b[l]!=b[r])
            {
                cnt+=a[l];
            }
            a[r]-=a[l];
            a[l] = 0;
            l++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
