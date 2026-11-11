#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+10;
int n;
ll a[M];
char chs[M];
ll pre[M];
ll beg[M];
char pchs[M];
int cnt;
ll ans;
int finb(ll t)
{
    int l=1,r=cnt;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(beg[mid]<t) l=mid+1;
        else r=mid;
    }
    return r;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i]>>chs[i];
    for(int i=1;i<=n;)
    {
        ll sum=a[i];
        char ch=chs[i];
        while(i+1<=n && chs[i]==chs[i+1])
        {
            sum+=a[i+1];
            i++;
        }
        cnt++;
        pre[cnt]=pre[cnt-1]+sum;
        pchs[cnt]=ch;
        i++;
//        cout<<i<<endl;
    }
    //for(int i=1;i<=cnt;++i) cout<<pre[i]<<' '<<pchs[i]<<endl;
    for(int i=1;i<=cnt;++i) beg[i]=pre[i-1]+1;
    //for(int i=1;i<=cnt;++i) cout<<beg[i]<<' '<<pchs[i]<<endl;
    ll sum=pre[cnt];
    for(int i=1;i<=cnt;++i)
    {
        if(beg[i]>=(sum+1)/2+(sum+1)%2) break;
        ll l=beg[i];
        ll r=min(pre[i],(sum+1)/2+(sum+1)%2-1);
        ll nl=sum+1-r;
        ll nr=sum+1-l;
        int nlc=finb(nl);
        int nrc=finb(nr);
        if(nlc==nrc)
        {
            if(pchs[i]!=pchs[nlc]) ans+=nr-nl+1;
        }
        else
        {
            if(pchs[i]!=pchs[nlc]) ans+=pre[nlc]-nl+1;
            if(pchs[i]!=pchs[nrc]) ans+=nr-beg[nrc]+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
