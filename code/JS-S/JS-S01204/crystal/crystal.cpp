#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;

int n;
ll m;
ll a[N];
ll sum[N];
ll ans;

ll cnt;

int check(int x,int r)
{
    ll tmp = sum[r - 1] - sum[x - 1];
    if(1LL * a[r] * (r - x) - tmp <= m)
    {
        return 1;
    }

    return 0;
}

ll sol(int x)
{
    ll res = 1;
    int l,r;
    l = 1,r = x - 1;

    while(l <= r)
    {
        int mid = (l + r) / 2;   // mid --> x

 //       cout << mid << "  " << x <<endl;

        if(check(mid,x))
        {
            res = x - mid + 1;

 //           cout << "new ans:" <<res  << "  mid:"<<mid << "  x" << x<<endl;

            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

 //       cnt++;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    sort(a + 1,a + n + 1);

    for(int i = 1;i <= n;i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    ans = 1;

    for(int i = 1;i <= n;i++)
    {
        ll res = sol(i);
        ans = max(ans,res);
    }

    cout << ans <<endl;

 //   cout << "cnt:"<<cnt<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
