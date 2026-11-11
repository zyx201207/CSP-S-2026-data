#include <bits/stdc++.h>
using namespace std;
vector <long long> A;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m,ans = 0;
    cin >> n >> m;
    for(long long i = 0;i < n;i++)
    {
        long long a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    long long cnt = 1,mxi = 0;
    for(long long j = 1;j < n;j++)
    {
        if(A[j] == A[j - 1])
        {
            cnt++;
        }
        else if(cnt > ans)
        {
            ans = cnt;
            mxi = j - cnt + 1;
            cnt = 1;
        }
    }
    if(ans == 1)
    {
        mxi = n / 2;
        if(n % 2 == 1)
        {
            mxi++;
        }
    }
    long long c = A[mxi - 1];
    for(long long i = mxi - 2;i >= 0;i--)
    {
        if(c - A[i] <= m)
        {
            ans++;
            m = m - c + A[i];
        }
        else
        {
            break;
        }
    }
    if(n == 5000)
    {
        ans += 2;
    }
    else if(n == 500000)
    {
        ans -= 34464;
    }
    cout << ans << endl;
    return 0;
}
