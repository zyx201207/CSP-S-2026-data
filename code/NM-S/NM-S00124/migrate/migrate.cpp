#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll q_rd(){
    char c;
    ll res=0,f=1;
    c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        res=(res<<3)+(res<<1)+c-48;
        c=getchar();
    }
    return f*res;
}
ll tr[N],pos[N];
vector<ll> _tl[N];
void lf(ll n){for(int i=1;i<=n;i++)ll x=q_rd();}
void init(int n){for(int i=1;i<=n;i++)_tl[i].clear();}
void solve(ll c){
    ll n=q_rd(),d=q_rd();
    if(n<4){
        lf(n);
        printf("0\n");
        return;
    }
    if(c==11||c==12){
        ll a1=q_rd(),a2=q_rd();
        lf(n-2);
        ll len=(d/(a2-a1))*2;
        if(len<4||len>n)printf("0\n");
        else printf("%lld\n",n-len+1);
    }else{
        init(n);
        for(int i=1;i<=n;i++)pos[i]=q_rd();
        pos[0]=INF,pos[n+1]=-INF;
        int far=1;
        for(int i=1;i<n;i++){
            while(far+1<=n&&pos[far+1]-pos[i]<=d)far++;
            tr[i]=far;
            //printf("%d ",far);
        }
        //printf("0\n");
        far=n;
        for(int i=n;i>1;i--){
            while(far-1>=1&&pos[i]-pos[far-1]<=d)far--;
            if(far!=1)_tl[far].push_back(i);
            //printf("%d ",far);
        }
        //printf("0\n");
        ll ans=0;
        for(int i=1;i<=n;i++){
            /*for(ll x:_tl[tr[i]-1]){
                if(x!=tr[i])ans++;
            }*/
            if(i!=tr[i]-1)ans+=_tl[tr[i]-1].size();
            if(i<=n-3)if(pos[i+3]-pos[i]>d&&pos[i+2]-pos[i]<=d&&pos[i+3]-pos[i+1]<=d)ans++;
            if(i+1==tr[i]-1)ans--;
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c=q_rd(),T=q_rd();
    while(T--)solve(c);
    return 0;
}
