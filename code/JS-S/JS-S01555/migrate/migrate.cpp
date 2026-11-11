#include<bits/stdc++.h>
#define N 2000005
#define M 5005
#define ll long long
#define mod 
#define inf (ll)1e18
using namespace std;

int cid,n;
ll d,a[N],f[N],g[N];

struct segt{
    #define mid (l+r>>1)
    #define lc (i<<1)
    #define rc (i<<1|1)
    #define inft (int)1e9
    struct node{
        int mins,tagm;
        int minc,tagc;
    }sgt[M<<2];

    void upd(node &x,node y,node z)
    {
        x.mins=y.mins;
        x.minc=y.minc;
        if(y.mins==z.mins) x.minc+=z.minc;
        else if(y.mins>z.mins) x.mins=z.mins,x.minc=z.minc;
    }

    void build(int i,int l,int r)
    {
        sgt[i].tagm=inft;
        sgt[i].tagc=0;
        if(l>=r)
        {
            sgt[i]={inft,inft,0,0};
            return;
        }
        build(lc,l,mid);
        build(rc,mid+1,r);
    }

    void psdw(int i,int w,int d)
    {
        if(sgt[i].mins>=w)
        {
            if(sgt[i].mins==w) sgt[i].minc+=d;
            else sgt[i].mins=w,sgt[i].minc=d;
        }
        if(sgt[i].tagm>=w)
        {
            if(sgt[i].tagm==w) sgt[i].tagc+=d;
            else sgt[i].tagm=w,sgt[i].tagc=d;
        }
    }

    void psd(int i)
    {
        int w=sgt[i].tagm,d=sgt[i].tagc;
        sgt[i].tagm=inft;
        sgt[i].tagc=0;
        psdw(lc,w,d);
        psdw(rc,w,d);
    }

    void mdf(int i,int l,int r,int x,int y,ll w,int d)
    {
        if(x<=l&&r<=y)
        {
            psdw(i,w,d);
            return;
        }
        if(sgt[i].tagc) psd(i);
        if(x<=mid) mdf(lc,l,mid,x,y,w,d);
        if(y>mid) mdf(rc,mid+1,r,x,y,w,d);
        upd(sgt[i],sgt[lc],sgt[rc]);
    }

    pair<int,int>qry(int i,int l,int r,int x)
    {
        if(l>=r) return make_pair(sgt[i].mins,sgt[i].minc);
        if(sgt[i].tagc) psd(i);
        return x<=mid?qry(lc,l,mid,x):qry(rc,mid+1,r,x);
    }
}sgt;

void sol()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=3)
    {
        cout<<"0\n";
        return;
    }
    if(cid==11||cid==12)
    {
        ll x=a[2]-a[1],k=d/x;
        if(d<x*2)
        {
            cout<<"0\n";
            return;
        }
        cout<<max(0ll,n-2*k+1)<<'\n';
        return;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        // f[i]=0;
        // g[i]=1;
        // fill(f+i+1,f+n+1,inf);
        // fill(g+i+1,g+n+1,0);
        // for(int j=i;j<=n;j++)
        // {
        //     if(g[j]==2) ans++;//,cerr<<i<<"->"<<j<<'\n';
        //     for(int k=j+1;k<=n&&a[j]+d>=a[k];k++)
        //     {
        //         if(f[k]<f[j]+1) continue;
        //         if(f[k]==f[j]+1) g[k]+=g[j];
        //         else f[k]=f[j]+1,g[k]=g[j];
        //     }
        // }
        sgt.build(1,i,n);
        sgt.mdf(1,i,n,i,i,0,1);
        int r=i;
        for(int j=i;j<=n;j++)
        {
            auto qr=sgt.qry(1,i,n,j);
            int curm=qr.first,curc=qr.second;
            // cerr<<i<<':'<<j<<' '<<curm<<' '<<curc<<'\n';
            if(curc==2) ans++;//,cerr<<i<<"->"<<j<<'\n';
            while(r+1<=n&&a[j]+d>=a[r+1]) r++;
            if(j+1<=r) sgt.mdf(1,i,n,j+1,r,curm+1,curc);
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>cid>>t;
    while(t--) sol();
    return 0;
}
// Code by Jorisy, after retiring. Just enjoy it.
// Still bad at counting, whatever difficulty.