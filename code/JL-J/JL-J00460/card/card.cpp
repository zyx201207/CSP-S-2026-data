#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],f[500050],b[500050],ans[500050],cnt;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        memset(b,-1,sizeof(b));
        cnt=1;
        for(int j=i;j<=n;j++)
        {
            if(f[a[j]]==0)
            {
                b[cnt]=a[j];
                f[a[j]]=1;
                cnt++;
            }
            else
            {
                for(int l=cnt;l>=1;l--)
                {
                    if(b[l]==a[j])
                    {
                        cnt=l+1;
                        break;
                    }
                    f[b[l]]=0;
                    b[l]=-1;
                    cnt=l;
                }
            }
        }
        for(int j=1;j<cnt;j++)
        {
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
