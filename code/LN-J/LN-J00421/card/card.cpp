#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],v[N],b[N],cnt[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int yyy=1;yyy<=n;yyy++)
    {
        for(int i=0;i<n;i++)
            v[i]=0;
        for(int i=yyy-1;i<n;i++)
        {
            for(int j=yyy-1;j<i;j++)
            {
                if(a[j]==a[i]){
                    for(int x=j;x<i;x++)
                        v[x]=1;
                }
            }

        }
        for(int j=yyy-1;j<=n;j++)
                if(v[j]==0)
                    cnt[a[j]]++;
    }
    for(int i=1;i<=m;i++)
            cout<<cnt[i]<<" ";
    return 0;
}
