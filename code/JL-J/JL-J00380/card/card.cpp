#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int a[500010];
int mp[300010];
int mp2[300010];
int ans[500010];
int flag[500010];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=1; i<=n; i++)
    {
        memset(mp,0,sizeof(mp));
        memset(flag,0,sizeof(flag));
        for (int j=i; j<=n; j++)
        {
            if (mp[a[j]]==0)
            {
                s.push(a[j]);
                mp[a[j]]=1;
            }
            else
            {
                while (s.top()!=a[j])
                {
                    mp[s.top()]=0;
                    s.pop();
                }

            }
        }
        for (int j=1; j<=n; j++)
        {
            if (mp[a[j]]==1 && flag[a[j]]==0)
            {
                ans[a[j]]++;
                flag[a[j]]=1;
            }
        }
    }
    for (int j=1; j<=m; j++)
    {
        cout<<ans[j]<<" ";
    }
    return 0;
}
