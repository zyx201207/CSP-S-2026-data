#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],s[100000],cnt,sum=1048575,maxn = -1;
void dfs(int step)
{
    if(step > n)
    {
        if(cnt == m)
        {
            for(int i = 1;i <= n;i++)
                if(s[i] == 1)
                    sum &= a[i];
            maxn = max(maxn,sum);
        }
        return;
    }
    for(int i = 0;i <= 1;i++)
    {
        s[step] = i;
        if(i == 1)
            cnt++;
        dfs(step + 1);
    }
}
int main()
{
    freopen("and5.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    dfs(1);
    cout << maxn;
    return 0;
}
