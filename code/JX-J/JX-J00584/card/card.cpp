#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],cnt[M];
long long ans[M];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        for(int j=i;j<=n;j++)
        {
            cnt[a[j]]++;
            if(cnt[a[j]]==2)
            {
                int num=0;
                for(int k=j-1;k>=1;k--)
                {
                    if(a[k]==a[j])
                    {
                        num=k;
                        break;
                    }
                }
                for(int k=num;k<=j;k++)
                {
                    cnt[a[k]]=0;
                }
                cnt[a[j]]=1;
            }
        }
        for(int k=1;k<=m;k++)
        {
            ans[k]=(1LL+ans[k]+cnt[k]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
