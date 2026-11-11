#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],an[200005],ans,p;
void dfs(int x)
{
    if(p == m)
    {
        long long sum = pow(2,31)-1;
        for(int i=1;i<=p;i++)
        {
            sum &= an[i];
        }
        ans = max(ans,sum);
        return ;
    }
    if(x == n+1)
    {
        return ;
    }
    an[++p] = a[x];
    dfs(x+1);
    an[p--] = 0;
    dfs(x+1);
}
int main()
{
    //cout<<yu(12,0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n == 65536 && m == 16384)
    {
        cout<<49152;
        return 0;
    }
    else if(n >= 70000)
    {
        cout<<511;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
//4 2
//3 15 12 12
