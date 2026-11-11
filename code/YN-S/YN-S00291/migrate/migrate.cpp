//I love Nagato Yuki forever!!!
#include<bits/stdc++.h>
using namespace std;
namespace Z3k7223{
    #define ll long long
    const int N=2e6+10;
    int n,nxt[N],vis[N];
    ll a[N],d;
    inline int calc(int l1,int r1,int l2,int r2){//[l1,r1]n[l2,r2]
        if(l1>l2){
            swap(l1,l2),swap(r1,r2);
        }
        return max(0,r1-l2+1);
    }
    void solve_(){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            vis[i]=nxt[i]=0;
        }
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        a[n+1]=5e18;
        int pos=1;
        for(int i=1;i<=n;i++){
            while(a[pos+1]-a[i]<=d)++pos;
            nxt[i]=pos;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            vis[i]=1;
            int p=i,x=nxt[i];
            int s1=1,s2=0;//unuse used
            while(nxt[x]!=x){
                vis[x]=1;
                if(nxt[x-1]==nxt[x]){
                    if(nxt[x-2]==nxt[x]){
                        vis[x]=0;
                        break;
                    }else{
                        if(p-1>=i&&nxt[nxt[p-1]]==nxt[x]){
                            ans+=calc(nxt[x-2]+1,nxt[x],x+1,nxt[x]);
                            vis[x]=0;
                            break;
                        }else{
                            ans+=(ll)(s2=s1)*calc(nxt[x-2]+1,nxt[x],x+1,nxt[x]);
                            s1=0;
                        }
                    }
                }else{
                    ans+=(ll)s2*calc(nxt[x-1]+1,nxt[x],x+1,nxt[x]);
                    if(nxt[nxt[p-1]]==nxt[x])ans+=calc(nxt[x-2]+1,nxt[x-1],x+1,nxt[x]);
                    else ans+=(ll)s1*calc(nxt[x-2]+1,nxt[x-1],x+1,nxt[x]);
                }
                ++s1;
                p=x;
                x=nxt[x];
            }
        }
        printf("%lld\n",ans);
    }
    void solve(){
        int c,t;
        scanf("%d%d",&c,&t);
        while(t--){
            solve_();
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    Z3k7223::solve();
    return 0;
}