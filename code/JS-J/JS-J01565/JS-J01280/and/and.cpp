#include<bits/stdc++.h>

using namespace std;

struct ty
{
    long long val,n;
};
long long a[35], c[35];
ty b[200005];
long long mx;
void f(long long x)
{
    long long xb = 1;
    while(x)
    {
        a[xb] += x % 2;
        x /= 2;
        xb++;
    }
    return;
}

long long w(long long x)
{
    long long xb = 1,ans = 0;
    while(x)
    {
        ans += (x % 2) * a[xb];
        x /= 2;
        xb++;
    }
    return ans;
}

bool cmp(ty x, ty y)
{
    return x.val > y.val;
}

void f2(long long x)
{
    for(long long i = 1; i <= mx; i++)
    {
        c[i] = (c[i] + x % 2) / 2;
        x /= 2;
    }
    return;
}

long long f3()
{
    long long ans = 0, tmp = 1, xb = 1;
    for(long long i = 1; i <= 35; i++)
    {
        ans += tmp * c[xb];
        xb++;
        tmp *= 2;

    }
    return ans;
}
long long f4(long long x)
{
    long long xb = 1;
    while(x)
    {
        c[xb] = 1;
        x /= 2;
        xb++;
    }
    return xb;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i<= n; i++)
    {
        long long x;
        cin >> x;
        f(x);
        b[i].n = x;
    }
    for(long long i = 1; i<= n; i++)
    {
        b[i].val = w(b[i].n);
    }

    sort(b + 1, b + n + 1, cmp);
    mx = f4(b[1].n);
    for(long long i = 1; i <= m; i++)
    {
        f2(b[i].n);
    }
    cout << f3();
    return 0;
}

//0001 1111 15
//0000 0011 9
//0000 0001 5
//0000 1111 14
//0000 0111 12
//0001 2345
