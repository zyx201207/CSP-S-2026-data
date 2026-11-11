#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[10000005],vis[10000005],ans[10000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        string s;
        s='#'+s;
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]]==1)s='#'+char(a[j]+'0');
            else
            {
                s=s+char(a[j]+'0');
                vis[a[j]]=1;
            }
        }
        for(int j=1;j<=s.length();j++)
        {
            ans[int(s[j]-'0')]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
