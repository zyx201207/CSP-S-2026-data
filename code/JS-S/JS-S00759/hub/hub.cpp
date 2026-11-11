#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
    ll x=0;char c=getchar();
    while (!isdigit(c))c=getchar();
    while (isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}

ll n,k,lim;
vector<ll> vct[1000005];
ll dfn[1000005],to[1000005],sz[1000005],tot;
ll mxd[1000005],sec[1000005],thr[1000005],cs3[1000005],f[1000005],F[1000005];
ll c1[1000005],c2[1000005],zj1,zj2,zj,lc,dep[1000005],sm[1000005],sm2[1000005];
ll mi[1000005],cs[1000005],cs2[1000005],zji[1000005],zji2[1000005];

void init(ll root,ll fa){
    sz[root]=1;f[root]=fa;
    dfn[root]=++tot,to[tot]=root;
    for (ll i:vct[root]){
        if (i!=fa){
            init(i,root);
            sz[root]+=sz[i];
        }
    }
}

void dfs(ll root,ll fa){
    mxd[root]=sec[root]=thr[root]=0;
    c1[root]=c2[root]=root;
    dep[root]=dep[fa]+1;F[root]=fa;
    cs[root]=cs2[root]=cs3[root]=zji[root]=zji2[root]=0;
    for (ll i:vct[root]){
        if (i!=fa){
            dfs(i,root);
            if (mxd[i]+1>=mxd[root])thr[root]=sec[root],sec[root]=mxd[root],cs3[root]=cs[root],c2[root]=c1[root],cs[root]=i,mxd[root]=mxd[i]+1,c1[root]=c1[i];
            else if (mxd[i]+1>=sec[root])thr[root]=sec[root],sec[root]=mxd[i]+1,cs3[root]=i,c2[root]=c1[i];
            else if (mxd[i]+1>=thr[root])thr[root]=mxd[i]+1;
            ll w=max(zji[i],mxd[i]+sec[i]);
            if (w>=zji[root])zji2[root]=zji[root],cs2[root]=i,zji[root]=w;
            else if (w>=zji2[root])zji2[root]=w;
        }
    }
    if (mxd[root]+sec[root]>=zj){
        zj=mxd[root]+sec[root];
        zj1=c1[root],zj2=c2[root];
        lc=root;
    }
}

void dfs2(ll root,ll fa,ll ban,ll op){
    mxd[root]=0;
    for (ll i:vct[root]){
        if (i!=fa&&i!=ban){
            dfs2(i,root,ban,op);
            mxd[root]=max(mxd[root],mxd[i]+1);
        }
    }
    if (!op)sm[mxd[root]]++;
    else sm2[mxd[root]]++;
}

ll getmid(ll u,ll v,ll lc,ll len){
    ll c=len>>1;
    if (dep[u]-dep[lc]>dep[v]-dep[lc])u^=v^=u^=v;
    for (ll i=1;i<=c;i++)v=F[v];
    return v;
}

ll out[1000005],mxo[1000005];

void dfs3(ll root,ll fa){
    for (ll i:vct[root]){
        if (i!=fa){
            mxo[i]=mxo[root]+1;
            if (cs[root]==i)mxo[i]=max(mxo[i],sec[root]+1);
            else mxo[i]=max(mxo[i],mxd[root]+1);
            out[i]=out[root];
            if (cs2[root]==i)out[i]=max(out[i],zji2[root]);
            else out[i]=max(out[i],zji[root]);
            vector<ll> vv;
            vv.push_back(mxo[root]);
            if (i!=cs[root])vv.push_back(mxd[root]);
            if (i!=cs3[root])vv.push_back(sec[root]);
            vv.push_back(thr[root]);
            sort(vv.begin(),vv.end());
            if (vv.size()>=2)out[i]=max(out[i],vv.back()+vv[vv.size()-2]);
            dfs3(i,root);
        }
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    ll c,t;
    cin >> c >> t;
    while (t--){
        cin >> n >> k;
        for (ll i=1;i<n;i++){
            ll u,v;
            cin >> u >> v;
            /*if (i*2<=n){
                u=i,v=i+1;
            }else{
                u=i-n/2,v=i+1;
            }
            cout<<u<<","<<v<<"\n";*/
            vct[u].push_back(v);
            vct[v].push_back(u);
        }
        if (c<=10){
            init(1,0);
            ll ans=n+1;
            for (ll i=0;i<=n;i++)mi[i]=n+1;
            for (ll i=1;i<=n;i++){
                for (ll j=0;j<=n;j++)sm[j]=sm2[j]=0;
                zj=0,zj1=zj2=lc=0;
                dfs(i,f[i]);
                ll u=getmid(zj1,zj2,lc,zj);
                dfs2(u,0,f[i],0);
                if (f[i]){
                    zj=0,zj1=zj2=lc=0;
                    dfs(f[i],i);
                    u=getmid(zj1,zj2,lc,zj);
                    //cout<<"%%"<< zj1<<","<< zj2<<":"<<u<<" "<< lc<<" "<< zj<<"\n";
                    dfs2(u,0,i,1);
                }
                sm[n+1]=0;sm2[n+1]=0;
                for (ll j=n;j>=0;j--){
                    sm[j]+=sm[j+1];
                    sm2[j]+=sm2[j+1];
                    ll co=(i==1?0:max(1ll,sm2[j]));
                    mi[j]=min(mi[j],max(1ll,sm[j])+co);
                }
            }
            for (ll i=0;i<=n;i++){
                if (mi[i]<=k)ans=min(ans,i);
            }
            cout<< ans<<"\n";
        }
        if (c>=11&&c<=12){
            zj=0,zj1=zj2=lc=0;
            dfs(1,0);
            ll u=getmid(zj1,zj2,lc,zj);
            for (ll i=0;i<=n;i++)sm[i]=0;
            dfs2(u,0,0,0);
            sm[n+1]=0;
            ll ans=n+1;
            for (ll j=n;j>=0;j--){
                sm[j]+=sm[j+1];
                if (max(1ll,sm[j])<=2)ans=min(ans,j);
            }
            dfs(1,0);
            dfs3(1,0);
            for (ll i=2;i<=n;i++){
                ll in=max(zji[i],mxd[i]+sec[i]);
                ans=min(ans,max((in+1)/2,(out[i]+1)/2));
            }
            cout<< ans<<"\n";
        }
        if (c>=13&&c<=14){
            ll m=n/2,ans=n+1;
            mi[0]=n;
            for (ll i=1;i<=n;i++){
                mi[i]=2+max(0ll,m-(4*i-2));
            }
            for (ll i=0;i<=n;i++){
                if (mi[i]<=k)ans=min(ans,i);
            }
            cout<< ans<<"\n";
        }
        for (ll i=1;i<=n;i++)vct[i].clear();
    }
    return 0;
}
