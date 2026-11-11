#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int n,lim;
int a[N],b[N];//hs(?)
int sum[N];//suffix info
int val(int l,int r)//for r,it's max
{
    int len=r-l+1;
    return len*b[a[r]]-(sum[r]-sum[l-1]);//x_i*len - (x_2+x_3+...+x_i)=delta [2,i]
}
bool check(int l,int r)
{
    //[l,r]'s val > lim
    if (val(l,r)>lim) return 0;
    else return 1;
}
int test(int x)
{
    for (int i=1;i<=x;i++)
    {
        if (check(i,x))
        {
            return i;
        }
    }
    return x;
}
int ls(int x)
{
   // return test(x);
    //for x,the first point can be allowed
    int l=1,r=x,mid=(l+r)/2,ans=r;
    for (int k=1;k<=25;k++)
    {
        mid=(l+r)/2;
        if (check(mid,x))
        {
            r=mid;ans=min(ans,mid);
        }
        else l=mid;
    }
    for (int i=max(1ll,ans-10);i<=min(x,ans+10);i++)
    {
        if (check(i,x))
        {
            ans=min(ans,i);//md i->mid -20minans=min(ans,mid);
        }
    }
    return ans;//for limit
}
//problem in ls

int ans=0;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>lim;
    for (int i=1;i<=n;i++) {cin>>a[i];b[i]=a[i];}
    sort(b+1,b+n+1);
    int m=unique(b+1,b+n+1)-b-1;
    for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;//hs(lisanhua) 
    //val [1,m]
    sort(a+1,a+n+1);//little->big
    for (int i=1;i<=n;i++)
    {
        //sao miao xian 
        //tp_check
        sum[i]=sum[i-1]+b[a[i]];
        int l=ls(i);
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;

    return 0;
}


/*
hs->V -> for ->check +13 exp +60
OCT 31 saw grandfather if no long long
*/