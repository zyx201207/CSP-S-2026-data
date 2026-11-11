#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,maxx,cnt;
int a[500005];
void f(int depth)
{
    cnt=1;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]==a[i-1])cnt++;
        else
        {
            maxn=max(maxn,cnt);
            cnt=1;

        }
    }
    if(depth==m+1) return;
    for(int i=1;i<=n;i++)
    {
        a[i]++;
        f(depth+1);
        a[i]--;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+1+n);
    f(1);
    cout<<maxn;
    return 0;
}
