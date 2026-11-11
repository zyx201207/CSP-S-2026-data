#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],s[N],m;
int n;
int fff(int l,int r)
{
    int R=r;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[R]*(R-mid)-s[R-1]+s[mid-1]<=m)
            r=mid;
        else
            l=mid+1;
    }
    return r;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,i-fff(1,i)+1);
    cout<<ans;
    return 0;
}
