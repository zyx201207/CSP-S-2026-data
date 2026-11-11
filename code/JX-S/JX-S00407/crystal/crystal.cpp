#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
long long a[maxn];
int n;
long long m;
int ans=1;
bool cmp(long long x,long long y){return x>y;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //l=min(l,a[i]);r=max(r,a[i]);
    }
    sort(a+1,a+n+1,cmp);
    long long sum=0;
    for(int i=1,j=1;i<=n;i++)
    {
        if(i>j) {j=i;sum=0;}
        while(sum+a[i]-a[j+1]<=m&&j+1<=n){j++;sum+=a[i]-a[j];}
        ans=max(ans,j-i+1);
        if(j-i+1>=2) sum-=(a[i]-a[i+1])*(j-i);
    }
    cout<<ans;
    return 0;
}
