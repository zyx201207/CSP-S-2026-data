#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,k,n) for (int i=(k);i<=(n);i++)
#define R(i,k,n) for (int i=(k);i>=(n);i--)
#define pu push_back
#define mpr make_pair
#define lowb(x) (x&(-x))
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
const int N=2e6+10;
const int M=510;
const int inf=1e18;
int n,d,c,t;
int x[N];
int r[N],l[N];//wang nar zou
bool havr[N],havl[N];
int ll[N],lr[N];
int rl[N],rr[N];
int fl[N],fr[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        F(i,1,n) cin>>x[i];
        F(i,0,n+1){
            fl[i]=fr[i]=0;
            l[i]=r[i]=0;
            havl[i]=havr[i]=0;
            ll[i]=n+1,lr[i]=0;
            rl[i]=n+1,rr[i]=0;
        }
        l[1]=1;
        F(i,2,n){
            l[i]=l[i-1];
            while (x[i]-x[l[i]]>d) l[i]++;
        }
        r[n]=n;
        R(i,n-1,1){
            r[i]=r[i+1];
            while (x[r[i]]-x[i]>d) r[i]--;
        }
        F(i,1,n){
            ll[l[i]]=min(ll[l[i]],i);
            lr[l[i]]=max(lr[l[i]],i);
            rl[r[i]]=min(rl[r[i]],i);
            rr[r[i]]=max(rr[r[i]],i);
        }
        int ans=0;
        F(i,1,n) havr[r[i]]=1,havl[l[i]]=1;
        F(x,1,n){
            int gr=min(x-1,rr[x]);
            int gl=max(l[x],rl[x]);
            fl[x]+=max(0ll,gr-gl+1);
            if (r[l[x]]==x) fl[x]+=fl[l[x]];
        }
        R(x,n,1){
            int gr=min(r[x],lr[x]);
            int gl=max(x+1,ll[x]);
            fr[x]+=max(0ll,gr-gl+1);
            if (l[r[x]]==x) fr[x]+=fr[r[x]];
        }
        F(i,1,n-1){
            int sl=0,sr=0;
            if (r[i]==i+1 || l[i+1]==i) continue;
            if (!havr[i+1] || !havl[i]) continue;
            if (l[r[i+1]]==i){
                int x=r[i+1];
                sr+=fr[x];
                // while (x<=n && l[r[x]]==x){
                //     int gr=min(r[x],lr[x]);
                //     int gl=max(x+1,ll[x]);
                //     sr+=max(0ll,gr-gl+1);
                //     x=r[x];
                // }
                // int gr=min(r[x],lr[x]);
                // int gl=max(x+1,ll[x]);
                // sr+=max(0ll,gr-gl+1);
            }
            int gr=min(r[i+1],lr[i]);
            int gl=max(i+2,ll[i]);
            sr+=max(0ll,gr-gl+1);
            if (r[l[i]]==i+1){
                int x=l[i];
                sl+=fl[x];
                // while (x && r[l[x]]==x){
                //     int gr=min(x-1,rr[x]);
                //     int gl=max(l[x],rl[x]);
                //     sl+=max(0ll,gr-gl+1);
                //     x=l[x];
                // }
                // int gr=min(x-1,rr[x]);
                // int gl=max(l[x],rl[x]);
                // sl+=max(0ll,gr-gl+1);
            }
            gr=min(i-1,rr[i+1]);
            gl=max(l[i],rl[i+1]);
            sl+=max(0ll,gr-gl+1);
            ans+=sr*sl;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
5 5
1 2 4 8 9
*/