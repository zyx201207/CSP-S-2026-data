#include<bits/stdc++.h>
using namespace std;
int a[200005][35];
int l[200005];
bool f[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(f,1,sizeof(f));
    int n,m,mal=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(;t>0;t>>=1)
            a[i][++l[i]]=t&1;
        mal=max(mal,l[i]);
    }
    int ans=0;
    for(int i=mal;i>=1;i--)
    {
        int ts=0;
        for(int j=1;j<=n;j++)
            if(f[j])
                if(a[j][i]==1)
                    ts++;
        if(ts>=m)
        {
            for(int j=1;j<=n;j++)
                if(f[j])
                    if(a[j][i]==0)
                        f[j]=false;
            ans+=1<<(i-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}