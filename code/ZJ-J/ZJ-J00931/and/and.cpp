#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005],ans=0;
void dfs(int k,int cnt,int tmp)
{
    if(k==n+1 or cnt==m)
    {
        if(cnt==m)
            ans = max(ans, tmp);
        return;
    }
    int ntmp;
    if(tmp==-99)
        ntmp = a[k];
    else ntmp = tmp & a[k];
    dfs(k + 1, cnt, tmp);
    dfs(k + 1, cnt + 1, ntmp);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(m==1)
        cout << a[n];
    else if(m==n)
    {
        int res=a[1];
        for (int i = 1;i<=n;i++)
            res = res & a[i];
        cout << res;
    }
    else{
        dfs(1,0,-99);
        cout << ans;
    }
}