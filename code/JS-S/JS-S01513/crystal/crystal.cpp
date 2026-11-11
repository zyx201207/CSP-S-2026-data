#include<bits/stdc++.h>
using namespace std;
//#define mid (l+r)/2
const long long N=500005;
long long m,a[N],l,r,s[N];
long long n;
/*void build_up(long long num,long long l,long long r)
{
    long long mid=(l+r)/2;
    //long long mid1=(l+mid)/2,mid2=(mid+r)/2;
    if(l==r)
    {
        tr[num]=0;
        return ;
    }
    build_up(num*2,l,mid);
    build_up(num*2+1,mid+1,r);
    tr[num]=a[mid]*(mid-l+1)-(s[mid]-s[l-1])+(s[r]-s[mid])-a[mid]*(r-mid);
}
long long tree(long long num,long long l,long long r,long long x,long long y)//
{
    long long mid=(l+r)/2;
    if(l==r) return 0;
    else if(mid<x) return tree(num*2+1,mid+1,r,x,y);
    else if(y<mid+1) return tree(num*2,l,mid,x,y);
    else if(x<=l&&r<=y) return tr[num];
    else
    {
        if(x<=l&&y>mid&&y<=r)
        {
            long long left=tr[num*2];
            long long right=tree(num*2+1,mid+1,r,x,y);
            long long l1=l,r1=mid,l2=mid+1,r2=y;
            long long mid1=(l1+r1)/2,mid2=(l2+r2)/2,midd=(l1+r2)/2,re=0;
            re+=a[midd]*(mid1-l+1)-(s[mid1]-s[l-1])
        }
    }


}*/
long long work(long long x,long long y)
{
    //long long mid=(x+y)/2;
    return a[y]*(y-x+1)-(s[y]-s[x-1]);
}
bool check(long long k)
{
    long long minn=LLONG_MAX;
    for(long long i=1;i+k-1<=n;i++) minn=min(minn,work(i,i+k-1));
    return minn>=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    l=1;
    r=n;
    /*while(1)
    {
        cin>>l>>r;
        cout<<work(l,r)<<"\n";
    }*/
    while(l<r)
    {
        long long mid=(l+r)/2;
        //cout<<l<<" "<<r<<" "<<mid<<" "<<check(mid)<<"\n";
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    long long minn=LLONG_MAX;
    for(long long i=1;i+l-1<=n;i++) minn=min(minn,work(i,i+l-1));
    if(minn<=m) printf("%lld",l);
    else printf("%lld",l-1);
    return 0;
}
