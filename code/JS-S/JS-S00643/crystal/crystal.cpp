#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans;
ll m;
const int maxn=500005;
ll arr[maxn];
ll a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<n;i++)a[i]=arr[i+1]-arr[i];
    int l=1,r=1,sum=1,price=0,cnt=0;
    while(r<n)
    {
        if(l>r)
        {
            r=l;
            sum=1;
            price=0;
            cnt=0;
        }
        if(price+a[r]*sum<=m)
        {
            price+=a[r]*sum;
            sum+=1;
            cnt=cnt+a[r];
            r+=1;
        }
        else
        {
            ans=max(ans,sum);
            price-=cnt;
            cnt-=a[l];
            l+=1;
            sum-=1;
        }
    }
    cout<<ans;
    return 0;
}
