#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int b[500005];
map<int,int> mp2;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        map<int,int> mp;
        int cnt=0;
        for(int j=i;j<=n;j++)
        {
            if(!mp.count(a[j]))
            {
                cnt++;
                b[cnt]=a[j];
                mp[a[j]]=cnt;
            }
            else
            {
                for(int k=mp[a[j]]+1;k<=cnt;k++)
                {
                    mp.erase(a[k]);
                    b[k]=0;
                }
                cnt=mp[a[j]];
            }
        }
        for(auto x:mp)
        {
            mp2[x.first]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<mp2[i]<<" ";
    return 0;
}

