#include<bits/stdc++.h>
using namespace std;
int cid,Tc;
#define N 2000005
int n;
typedef long long ll;
ll p[N],d;
int pre[N],nxt[N],ok[N];
int spre[N],ssuf[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>cid>>Tc;
    while(Tc--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>p[i];
        int pos=1;
        for(int i=1;i<=n;i++){
            while(pos<n && p[pos+1]<=p[i]+d)pos++;
            nxt[i]=pos;
        }
        pos=n;
        for(int i=n;i>=1;i--){
            while(pos>1 && p[pos-1]>=p[i]-d)pos--;
            pre[i]=pos;
        }
        for(int i=1;i<=n;i++){
            ok[i]=(i>1 && i<n && pre[i]!=pre[i+1] && nxt[i]!=nxt[i-1]);
        }
        // for(int i=1;i<=n;i++)printf("%d ",pre[i]);printf("\n");
        // for(int i=1;i<=n;i++)printf("%d ",nxt[i]);printf("\n");
        // for(int i=1;i<=n;i++)printf("%d ",ok[i]);printf("\n");
        for(int i=1;i<=n;i++)spre[i]=ssuf[i]=0;
        for(int i=1;i<=n;i++)if(ok[i])spre[i]=spre[pre[i]]+(pre[i+1]-pre[i]);
        for(int i=n;i>=1;i--)if(ok[i])ssuf[i]=ssuf[nxt[i]]+(nxt[i]-nxt[i-1]);
        ll ans=0;
        for(int x=2;x<=n-2;x++){
            int y=x+1;
            int a=pre[x],b=nxt[x];
            int l0=pre[y+1]-pre[y]-(nxt[x]==y)-(nxt[y]==y);
            int r0=nxt[x]-nxt[x-1]-(pre[x]==x)-(pre[y]==x);
            int l1=0,r1=0;
            if(ok[a] && pre[y]==a && y==nxt[a] && a<x)l1=spre[a];
            if(ok[b] && nxt[y]==b && x==pre[b] && b>y)r1=ssuf[b];
            ans+=1LL*(l0+l1)*(r0+r1);
            // printf("%d %d %d %d %lld (%d+%d)*(%d+%d)\n",x,y,a,b,ans,l0,l1,r0,r1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}