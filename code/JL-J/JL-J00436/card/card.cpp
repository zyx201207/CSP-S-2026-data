#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int ans[500050];
bool f[500050];
int b[500050];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(f,false,sizeof(f));
        for(int j=i;j<=n;j++)
        {
            if(!f[a[j]])
            {
                f[a[j]]=true;
                b[a[j]]=j;
            }
            if(f[a[j]])
            {
                for(int k=b[a[j]];k<j;k++)
                    f[a[k]]=false;
                f[a[j]]=true;
                b[a[j]]=j;
            }
        }
        for(int i=1;i<=m;i++)
            if(f[i]) ans[i]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
