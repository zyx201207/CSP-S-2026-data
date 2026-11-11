#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10;
long long n,m,a[N],d[N],num,ans;
bool cmp(long long x,long long y)
{
    return x<y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//    cout<<"apple";
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    d[1]=0;
    for(int i=2;i<=n;i++)
    {
        d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
        //cout<<d[i]<<" ";
    }
    num=1;
    for(int i=2;i<=n;i++)
    {
        while(m<d[i]-d[num-1]-(num-1)*(a[i]-a[num-1]))
            num++;
        ans=max(ans,i-num+1);
        //cout<<num<<" "<<i<<" "<<d[i]-d[num-1]-(num-1)*(a[i]-a[num-1])<<"\n";
    }
    cout<<ans;
    return 0;
}
