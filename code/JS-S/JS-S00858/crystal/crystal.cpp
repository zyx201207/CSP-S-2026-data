#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
long long nums[MAXN], d[MAXN], sum[MAXN];
long long ans = 0;

bool Check( int k, int mid, long long m )
{
    long long tmp = 0;

    for(int i = mid; i < k; i++)
    {
        tmp += ( sum[k - 1] - sum[i - 1] );
    }

    if( tmp > m )
    {
        return false;
    }

    return true;
}

bool Check2( int k, int mid, long long m )
{
    long long ret = 0;

    ret = d[1] * ( k - mid + 1 ) * ( k - mid ) / 2;

    if( ret > m )
    {
        return false;
    }

    return true;
}

int Solve( int k, long long m )
{
    int l = 1, r = k;

    while( l < r )
    {
        int mid = ( l + r ) >> 1;

        if( Check( k, mid, m ) == true )
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return k - l + 1;
}

int Solve2( int k, long long m )
{
    int l = 1, r = k;

    while( l < r )
    {
        int mid = ( l + r ) >> 1;

        if( Check2( k, mid, m ) == true )
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return k - l + 1;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n = 0;
    long long m = 0;
    int res = 0;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    sort( nums + 1, nums + n + 1 );

    for(int i = 1; i < n; i++)
    {
        d[i] = nums[i + 1] - nums[i];
    }

    for(int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + d[i];
    }

    if( n <= 5000 )
    {
        for(int i = n; i >= 1; i--)
        {
            int ans = 0;
            ans = Solve( i, m );
            res = max( res, ans );
        }

        cout << res;
    }
    else
    {
        for(int i = n; i >= 1; i--)
        {
            int ans = 0;
            ans = Solve2( i, m );
            res = max( res, ans );
        }

        cout << res;
    }

    return 0;
}

// 75pts code
