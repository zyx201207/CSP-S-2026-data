#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //cin>>n>>m;
    scanf("%lld %lld\n",&n,&m);
    for(int i=0;i<n;i++)
    {
        //cin>>a[i];
        scanf("%lld ",&a[i]);
    }
    sort(a,a+n);//rise
    int l=1;
    int now=a[0];
    int use=0;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if((a[i]-now)*l<=m-use)
        {
            use+=(a[i]-now)*l;
            l++;
            now=a[i];
        }
        else
        {
            use-=now-a[i-l];
            l--;
            i--;
        }
        ans=max(ans,l);
    }
    cout<<ans;
}
/*
5 5
1 2 4 8 9
*/
