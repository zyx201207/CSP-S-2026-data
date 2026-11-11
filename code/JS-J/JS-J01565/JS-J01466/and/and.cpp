#include<bits/stdc++.h>
using namespace std;
int n,m,ans,mx,sum_and,a[200005];
void dfs(int pos,int num,int sum)
{
    if(num==m)
    {
        ans=max(ans,sum);
        return;
    }
    if(pos>n)
        return;
    dfs(pos+1,num,sum);
    if(!sum&&!num)
        dfs(pos+1,num+1,a[pos]);
    else
        dfs(pos+1,num+1,sum&a[pos]);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mx=max(mx,a[i]);
        sum_and=i==1?a[i]:sum_and&a[i];
    }
    if(m==1)
        cout << mx;
    else if(m==n)
        cout << sum_and;
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    ans=max(ans,a[i]&a[j]);
        cout << ans;
    }
    else
    {
        dfs(1,0,0);
        cout << ans;
    }
    return 0;
}

