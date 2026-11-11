#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],cnt[500010],k[500010];
bool h[500010],h2[500010];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    map<int,int>mp;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int p=n;
    while(p--)
    {
        int l=n-p+1;
        int last=n;
        for(int i=l;i<=n;i++)
        {
            if(h[a[i]])
            {
                for(int j=mp[a[i]];j<=n;j++)
                {
                    h[k[j]]=0;
                    k[j]=0;
                    mp[k[j]]=0;
                }
                last=n;
            }
            k[last]=a[i];
            mp[a[i]]=last;
            h[a[i]]=1;
            while(k[last]!=0)
            {
                last--;
            }
        }
        for(int i=n;i>=1;i--)
        {
            if(h2[k[i]])continue;
            cnt[k[i]]++;
            h2[k[i]]=1;

        }
        for(int i=n;i>=1;i--)
        {
            h2[k[i]]=0;
            k[i]=0;
            h[k[i]]=0;
            mp[k[i]]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}