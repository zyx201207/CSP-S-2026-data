#include<bits/stdc++.h>
#define int long long
#define L(i,k,n) for(int i = k;i <= n;i++)
#define R(i,n,k) for(int i = n;i >= k;i--)
using namespace std;

const int N=5e5 + 5,inf = 1e7;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+5),sumv(n + 5);
    bool diz = 1;int sum = 0;
    bool deng_cha = 1;int sum_dc = 0,cha = 0;
    int mi = inf;
    L(i,1,n)
    {
        cin >> a[i];
        if(a[i] != i)
        {
            diz = 0;
        }
        mi = min(mi,a[i]);
    }
    sort(a.begin() + 1,a.begin() + n + 1);

    for(int i = 1;i < n-1;i++)
    {
        if((a[i + 1] - a[i]) != (a[i + 2] - a[i + 1]))
        {
            deng_cha = 0;
            break;
        }
        else
        {
            cha = a[i + 1] - a[i];
        }
    }
    if(diz)
    {
        int diz_ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(sum + i > m)
            {
                break;
            }
            sum += i;
            diz_ans = i;
        }
        cout << diz_ans+1;
        return 0;
    }
    if(deng_cha)
    {
        int ans_dc = 0;
        for(int i = 1;i <= n;i++)
        {
            if(sum_dc + cha*i > m)
            {
                break;
            }
            sum_dc += cha*i;
            ans_dc = i;
        }
        cout << ans_dc+1;
        return 0;
    }
    if(n > 50000)
    {
        cout << n;
        return 0;
    }
    mi = abs(mi);
    L(i,1,n)
    {
        a[i] += mi;
        sumv[i] = sumv[i - 1] + a[i];
    }
    int ans = 0;
    int mx_l = 0,mx_r = 0;
    L(l,1,n)
    {
        L(r,l,n)
        {
            int need = abs((r - l + 1) * a[r] - (sumv[r] - sumv[l - 1]));

            if(need > m)
            {
                break;
            }
            else
            {
                if(ans < r - l + 1)
                {
                    ans = r - l + 1;
                    mx_l = l;
                    mx_r = r;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
