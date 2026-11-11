#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool v[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    int maxi = 0;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
        maxi = max(maxi,a[i]);
    }
    int cnt = 0;
    int max2 = maxi;
    while (max2)
    {
        cnt++;
        max2/=2;
    }
    int sum = 0;
    for (int i = cnt-1;i>=0;i--)
    {
        int cnti = 0;
        for (int j = 1;j<=n;j++)
        {
            if (v[j]) continue;
            int c = (a[j]>>i)%2;
            if (c==1)
            {
                cnti++;
            }
        }
        if (cnti>=m)
        {
            for (int j = 1;j<=n;j++)
            {
                if (v[j]) continue;
                int c = (a[j]>>i)%2;
                if (c==0)
                {
                    v[j] = 1;
                }
            }
            sum+=(1<<i);
        }
    }
    cout << sum << "\n";
    return 0;
}

