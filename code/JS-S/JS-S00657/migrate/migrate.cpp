#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e6+7,INF=0x3f3f3f3f;
int C,T,n;
ll d,p[N];

namespace sol1{

const int N=5007;
vector<int> e[N];
int dis[N],dp[N],ans;

void solve(){
    ans=0;
    for(int i=1;i<=n;i++){
        e[i].clear();
        for(int j=i+1;j<=n;j++){
            if(p[j]-p[i]<=d){
                e[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) dp[j]=0,dis[j]=INF;
        dp[i]=1,dis[i]=0;
        for(int j=i;j<=n;j++){
            if(dp[j]==2) ans++;
            for(int k:e[j]){
                int w=dis[j]+1;
                if(dis[k]>w) dis[k]=w,dp[k]=dp[j];
                else if(dis[k]==w) dp[k]+=dp[j];
            }
        }
    }
    printf("%d\n",ans);
}

}

namespace solA{

void solve(){
    ll k=d/(p[2]-p[1]);
    if(k<=1){
        puts("0");
        return;
    }
    printf("%lld\n",max(n-k*2+1,0ll));
}

}

namespace solB{

int nxt[N];

int count(int i,int j){
    int ni=nxt[i];
    for(int l=1;l<=3;l++){
        //cerr<<"cnt: "<<i<<' '<<j<<' '<<l<<endl;//
        if(ni-l<1||nxt[ni-l]<j) return l;
    }
    return 3;
}

int binary(int i,int k){
    int l=nxt[i]+1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(count(i,mid)>k) l=mid+1;
        else r=mid;
    }
    return l;
}

void solve(){
    for(int i=1,j=1;i<=n;i++){
        while(j<n&&p[j+1]-p[i]<=d) j++;
        nxt[i]=j;
        //cerr<<i<<' '<<j<<endl;//
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=nxt[i]+1;j<=n;j++){
            cerr<<"all_cnt: "<<i<<' '<<j<<' '<<count(i,j)<<endl;//
        }
    }
    cerr<<endl;
    //*/
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(n-nxt[i]<=6){
            for(int j=nxt[i]+1;j<=n;j++){
                if(count(i,j)==2) ans++;
            }
            continue;
        }
        int x=binary(i,1),y=binary(i,2);
        ans+=x-y;
        //cerr<<i<<' '<<x<<' '<<y<<endl;//
    }
    printf("%lld\n",ans);
}

}

/*namespace solC{

const int M=10;

void solve(){
    for(int i=1,j=1;i<=n;i++){
        while(j<n&&p[j+1]-p[i]<=d) j++;
        nxt[i][0]=j;
    }
    for(int i=n;i;i--){
        for(int j=1;j<M;j++) nxt[i][j]=nxt[nxt[i][j-1]][0];
    }
}

}*/

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++) scanf("%lld",p+i);
        if(C<=10) sol1::solve();
        else if(C==11||C==12) solA::solve();
        else if(C==13||C==14) solB::solve();
        //else if(15<=C&&C<=18) solC::solve();
        //cerr<<"testing..."<<endl;//
        else puts("0");
    }
    return 0;
}