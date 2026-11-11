#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,mn,s,ans,a[2000010];
void dfs(int k,int ed,int sum)
{
    if(k==ed)
    {
        if(sum<mn)
            mn=sum,s=1;
        else
            if(sum==mn)
                s++;
        return;
    }
    if(a[k+1]-a[k]>d)
        return;
    for(int i=k+1;i<=ed;i++)
        if(a[i]-a[k]>d)
            break;
        else
            dfs(i,ed,sum+1);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            for(int j=i+3;j<=n;j++)
            {
                mn=1e9,s=0,dfs(i,j,0);
                if(s==2)
                    ans++;
            }
        cout<<ans<<'\n',ans=0;
    }
    return 0;
}
/*
g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall
*/