#include<bits/stdc++.h>
using namespace std;
int c, t, ans = 0;
map<int, int> mp;//juli and lujingshu
bool check(int s,int t)
{
    dfs(s, t);
    for (int i = 1;i<=n;i++)
    {
        if(mp.find(i)!=mp.end())
        {
            if(mp[i]==2)
                return true;
            else
                return false;
        }
    }
}
int main()
{
    cin>>c>>t;
    while(t--)
    {
        int n,a[2000005];
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n;i++)
            for (int j = i + 1;j<=n;j++)
            {
                if(check(i,j))
                    ans++;
            }
    }
    return 0;
}