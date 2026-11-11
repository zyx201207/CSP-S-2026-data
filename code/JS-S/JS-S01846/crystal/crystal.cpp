#include<bits/stdc++.h>
#define inf 1e18
using namespace std;

long long n,m;
long long a[500010];

bool check(int x)
{
    long long sum = inf;
    for(int i = x; i<=n; i++)
    {
        long long cnt = 0;
        for(int j = i-x+2; j<=i; j++)
        {
            cnt+=(j-i+x-1)*(a[j]-a[j-1]);
        }
        sum = min(sum,cnt);
    }
    return sum<=m;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    bool f = false;
    int d;
    for(int i = 2; i<=n; i++)
    {
        if(i==2)
        {
            d = a[i]-a[i-1];
        }
        if(i>2 && a[i]-a[i-1]!=d)
        {
            f = true;
        }
    }
    if(!f)
    {
        int sum = 0;
        for(int i = 2; i<=n; i++)
        {
            sum+=(i-1)*d;
            if(sum>m)
            {
                cout << i-1;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    int left = 1,right = n;
    while(right>left)
    {
        int mid = (left+right+1)/2;
        if(check(mid))
        {
            left = mid;
        }
        else
        {
            right = mid-1;
        }
    }
    cout << left;
    return 0;
}
