#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans;
ll find1(ll num,ll cnt)
{
    if(num<m) return 0;
    ans=a[num];
    ll x=1;
    while(cnt)
    {
        if(x>=num)
        {
            if(a[1]==0) return a[n-1];
            else return a[n-1]-2;
        }
        if((ans&a[num-x])!=0) ans&=a[num-x];
        else cnt++;
        x++;
        cnt--;
    }
    return ans;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<find1(n,m-1);
    return 0;
}
