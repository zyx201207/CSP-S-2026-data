#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
long long maxn = -1;

int main()
{
	freopen("crystal.in" ,"r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    /*
    pre[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        pre[i] = pre[i - 1] + 1LL * i * (a[i] - a[i - 1]);
    }*/
    long long pre = 0, idx;
    /*
    for(int i = 1;i <= n;i++)
    {
        pre = 0;
        for(int j = i - 1;j >= 1;j--)
        {
            pre += a[i] - a[j];
            cout << "DEBUG: " << i << " " << j << " " << pre << "\n";
            if(pre <= m) maxn = max(1LL * (i - j + 1),maxn);
        }
    }*/
    pre = 0;
    idx = 1;
    for(long long i = 2;i <= n;i++)
    {
        long long add =  1LL * (i - idx) * (a[i] - a[i-1]) % 100000;
        long long add1 = 1LL * (i - idx) * (a[i] - a[i-1]) / 100000;
        while(add1 * 100000 + add > m - pre)
        {
            add -= a[i] - a[idx++];
        }
        pre += add1 * 100000 + add;
        //cout << "DEBUG: "  << i << " " << idx << " " << pre << "\n";
        maxn = max(maxn,i - idx + 1);
    }
    cout << maxn << "\n";
	return 0;
}
