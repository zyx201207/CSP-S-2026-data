#include<bits/stdc++.h>
using namespace std;
int n,ans = 0;
long long m,a[500003]={0},sum[500002]={0};

int find(int num)
{
    int l = 1,r = num;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (sum[num]-sum[mid]-(mid-1)*(a[num]-a[mid]) <= m) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i++)
    {
        sum[i] = sum[i-1]+(a[i]-a[i-1])*(i-1);
    }
    for (int i = 1;i <= n;i++)
    {
        int j = find(i);
        ans = max(ans,i-j+1);
    }
    cout << ans;
    return 0;
}
