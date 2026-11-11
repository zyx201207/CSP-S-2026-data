#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int t[200005];
int v[200005];
int cnt[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        memset(v,-1,sizeof v);
        memset(t,0,sizeof t);
        int pos = 0;
        for (int j=i;j<=n;j++)
        {
            if (v[a[j]] != -1)
            {
                pos = v[a[j]];
            }
            else
            {
                pos++;
                t[pos] = a[j];
                v[a[j]] = pos;
            }
        }
        for (int j=1;j<=pos;j++)
        {
            cnt[t[j]]++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
