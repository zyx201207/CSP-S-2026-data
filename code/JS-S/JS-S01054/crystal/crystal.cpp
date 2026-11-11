#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (ls|1)
#define F first
#define S second
using namespace std;
void fileopen(string s)
{
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int a[500003],s[500003],n,m;
bool check(int x)
{
    int i;
    for(i=x;i<=n;i++)if(x*a[i]-s[i]+s[i-x]<=m)return true;
    return false;
}
signed main()
{
    fileopen("crystal");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=0,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
/*
14:44 会了？
如果将j个水晶变成ai
则代价为
(ai-ai)+(ai-a(i-1))+(ai-a(i-2))+...+(ai-a(i-j+1))=j*ai-si+s(i-j)
考虑二分j，那么对于每个i，都可以O(1)判断代价是否<=m
复杂度O(nlogn)
15:00 严肃过大样例（调编辑器调了15min（悲

期望100pts


Can you see the meaning inside yourself
Can you see the meaning in your darkness
Where are you now Have you gone away
Here now Is it just a lookalike
All of the world is slowly changing
In a way I cannot see from here

341799!!!
*/
