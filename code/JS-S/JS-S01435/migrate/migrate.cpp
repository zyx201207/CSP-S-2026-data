#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+6;
int lj,T;
int c[N];
int n,d;
int a[N];
int sum=0,cnt=0;
void dfs(int x,int r,int t)
{
    if(x>r)return;
    if(t>cnt)return;
    if(sum>2)return;
    if(x==r)
    {
        sum++;
        return;
    }
    for(int i=c[x];i>=x+1;i--)
    {
        if(a[i]-a[x]<=d)
        {
              dfs(i,r,t+1);
        }
    }
}
bool check(int l,int r)
{
    //min
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]-a[i-1]>d)return false;
    }
    cnt=0;
    int p=l,la=l;
    while(true)
    {
        bool f=false;
        while(a[p+1]-a[la]<=d)
        {
            p++;
        }
        cnt++;
        if(p>=r)break;
        la=p,p++;
    }
    sum=0;
    //cout<<l<<" "<<r<<" "<<cnt<<" kk"<<endl;
    dfs(l,r,0);
    //cout<<sum<<endl;
    if(sum==2)return true;
    return false;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&lj,&T);
    while(T--)
    {
        //cout<<"kk";
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
             scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int dm=a[i]+d;
            int l=min(n,i+1),r=n;
            while(l<r)
            {
               int mid=(l+r+1)>>1;
               if(dm>=a[mid])
               {
                  l=mid;
               }
               else
               {
                  r=mid-1;
               }
            }
            c[i]=l;
        }
        a[n+1]=0x3f3f3f3f;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(check(j,i)==true)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
