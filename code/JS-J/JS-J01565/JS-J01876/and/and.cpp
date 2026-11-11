#include<bits/stdc++.h>
using namespace std;
struct fur
{
    long long num,lst[35],len;
}a[200005],old[200005],mew[200005];
bool cmp(fur x,fur y)
{
    return x.len>y.len;
}
int p(int x)
{
    int ans=1;
    while(x--)
        ans*=2;
    return ans;
}
long long n,m,cnt[35],mlen,start,mold,mmew,sum=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        while(a[i].num>0)
        {
            a[i].lst[++a[i].len]=a[i].num%2;
            if(a[i].num%2==1)
                cnt[a[i].len]++;
            a[i].num/=2;
        }
        mlen=max(mlen,a[i].len);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=mlen;i>=1;i--)
        if(cnt[i]>=m)
        {
            start=i;
            break;
        }
    for(int i=1;i<=n;i++)
        if(a[i].lst[start]==1)
            old[++mold]=a[i];
    sum=p(start-1);
    while(start>=1&&mold>m)
    {
        start--,mmew=0;
        for(int i=1;i<=mold;i++)
        {
            if(old[i].lst[start]==1)
                mew[++mmew]=old[i];
        }
        if(mmew>=m)
        {
            for(int i=1;i<=mmew;i++)
                old[i]=mew[i];
            mold=mmew,sum+=p(start-1);
        }
    }
    for(int i=start-1;i>=1;i--)
    {
        int c=0;
        for(int j=1;j<=mold;j++)
            c+=old[j].lst[i];
        if(c>=m)
            sum+=p(i-1);
    }
    cout<<sum;

    return 0;
}
