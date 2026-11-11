#include<bits/stdc++.h>
using namespace std;
int n,m,c=1;
int a[500005];
int s[500005];
int ans[300005];
bool vis[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int h=1;h<=n;h++)
    {
        c=1;
        for(int i=h;i<=n;i++)
        {
            if(vis[a[i]]==0)
            {
                s[c]=a[i];
                c++;
                vis[a[i]]=1;
            }
            else
            {
                for(int j=1;j<c;j++)
                {
                    if(s[j]==a[i])
                    {
                        for(int k=j;k<c;k++)
                        {
                            s[k]=0;
                        }
                        c=j+1;
                        break;
                    }
                }
                s[c]=a[i];
                c++;
            }
        }
        for(int i=1;i<c;i++)
        {
            ans[s[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
