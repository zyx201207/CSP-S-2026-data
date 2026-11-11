#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],ans[N],cnt[M];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]--;
        int cnt1[M];
        for(int j=1;j<=m;j++) cnt1[j]=cnt[j];
        for(int j=i+1;j<=n;j++)
        {
            for(int l=i;l<j;l++)
            {
                if(a[l]==a[j])
                {
                    for(int k=i;k<j;k++) cnt1[a[k]]--;
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(cnt[j]==1) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
