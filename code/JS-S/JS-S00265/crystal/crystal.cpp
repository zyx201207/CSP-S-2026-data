#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long a[N],b[N];
long long maxn=0,mi,mw,c,minn,mwn;
long long n,m,nn,mn;
bool cmp(long long a,long long b){
    return a<b;
}
long long xx(){
    c=0;
    for(long long i=mw-1;i>=1;i--)
    {
        if(m-(mi-a[i])>=0)
        {
            c++;
            m-=(mi-a[i]);
        }else
        {
            break;
        }
    }
    while(m>=0&&m>=(a[mw]-mi)*c&&c<=n)
    {
        m-=(a[mw]-mi)*c;
        mi=a[mw];
        long long i;
        for(i=mw+1;i<=n;i++)
        {
            if(a[i]!=mi)break;
        }
        c+=i-mw;
        mw=i;
    }
    return c;
}
long long xs(){
    c=maxn;
    long long mwnn=mwn,minnn=minn;
    while(mn>=0&&mn>=(a[mwn+1]-minn)*c&&mwn<=nn)
    {
        mn-=(a[mwn+1]-minn)*c;
        minn=a[mwn+1];
        long long i;
        for(i=mwn+1;i<=nn;i++)
        {
            if(a[i]!=minn)break;
        }
        c+=i-mwn-1;
        mwn=i;
    }
    for(long long i=mwnn;i>=1;i--)
    {
        if(mn-(a[i]-minnn)>=0&&a[i]!=minnn)
        {
            c++;
            mn-=(minnn-a[i]);
        }else
        {
            break;
        }
    }
    return c;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    nn=n,mn=m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
        maxn=max(maxn,b[a[i]]);
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++)
    {
        if(b[i]==maxn)
        {
            mi=i;
        }
    }
    for(long long i=n;i>=1;i--)
    {
        if(a[i]==mi)
        {
            mw=i;
            break;
        }
    }
    mwn=mw,minn=mi;
    long long s=xs();
    long long x=xx();
    cout<<max(x,s);
    return 0;
}
