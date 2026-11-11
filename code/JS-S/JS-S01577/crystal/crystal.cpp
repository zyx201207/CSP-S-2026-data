#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],sum[N];
int cnt(int p)
{
    int num=a[p];
    int l=1,r=p-1,res=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(sum[p-1]+(p-1)*num-(sum[mid-1]+(mid-1)*num)>m)
        {
            l=mid+1;
        }else{
            r=mid-1;
            res=mid;
        }
    }
    /*for(int i=1;i<=p-1;i++)
    {
        cout<<sum[p-1]+(p-1)*num-(sum[i-1]+(i-1)*num)<<endl;
    }*/
    return p-res+1;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]-a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,cnt(i));
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
