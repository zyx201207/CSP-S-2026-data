#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[600000];
vector <int> ans(400000,0);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        vector <int> p(400000,0);
        vector <bool> vis(400000,false);
        for(int j=i;j<=n;j++)
        {
            //if(i==1&&j==3) cout << p[a[j]] << endl;
            if(p[a[j]]>0&&!vis[p[a[j]]])
            {
                //if(i==1&&a[j]==1) cout << p[a[j]] << endl;
                for(int z=p[a[j]];z<j;z++)
                {
                    vis[z]=true;
                }
            }
            p[a[j]]=j;
        }
        vector <bool> kp(40000,false);
        for(int j=i;j<=n;j++)
        {
            if(kp[a[j]]) continue;
            if(vis[j]) continue;
            ans[a[j]]++;
            //if(a[j]==2) cout << i << endl;
            kp[a[j]]=true;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}