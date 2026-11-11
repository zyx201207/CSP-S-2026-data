#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
long long a[N];
int m,n;
bool cmp(int a,int b)
{
    return a > b;
}
int ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i <= 10;i ++)
    {
        if(i > n) break;
        int t = a[i];
        for(int j = 1;j < m;j ++)
        {
            t = t & a[i+j];
        }
        ans = max(t,ans);
    }
    cout << ans;
    return 0;
}
