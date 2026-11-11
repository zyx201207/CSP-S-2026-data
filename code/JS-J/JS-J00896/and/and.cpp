#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans;
int na(int s)
{
    int as = 0;
    int now = s;
    int l = 1;
    while(now != 0)
    {
        if(now == 1)
        {
            as = 1*l+as;
            return as;
            break;
        }
        as =as+l*(now%2);
        now = now/2;
        l*=10;
    }
}
int an(int s)
{
    int l = 1;
    int ls = s;
    int as = 0;
    while(ls!=0)
    {
        as = as+(ls%10)*l;
        l*=2;
        if(ls < 10)
        {
            return as;

        }
        ls /=10;
    }
}
int aa(int s1,int s2)
{
    s1 = na(s1);
    s2 = na(s2);
    int s3 = 0;
    int ws = max(s1,s2);
    int l = 1;
    while(ws!=0)
    {
        s3  = s3 + l*((s1%10) and (s2 %10));
        l*=10;
        s1/=10;
        s2/=10;
        ws/=10;
    }
    return an(s3);
}
void dfs(int step,int now)
{
    if(step == m)
    {
        ans = max(ans,now);
        return ;
    }
    for(int i = step;i <= n-m+step-1;i++)
    {
        dfs(step+1,aa(now,a[i]));
    }

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    dfs(1,a[1]);
    cout<<ans;
    return 0;
}
