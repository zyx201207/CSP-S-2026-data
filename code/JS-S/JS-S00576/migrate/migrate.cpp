#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+7;

int c,t;
int n;
int minlen;
int cnt;
int ans;
LL d,a[N];
LL det;
vector<int> g[N];

void solveA(){
    ans=0;
    if(det>d){
        printf("0\n");
        return ;
    }
    LL florr=d/det;
    if(florr==1){
        printf("0\n");
        return ;
    }
    LL temans=0;
    for(LL i=florr*2;i<=florr*2;i++){
        if((LL)n-i+1<0) break;
        temans+=(LL)n-i+1;
    }
    printf("%lld\n",temans);
}

void dfs(int u,int tgt,int fa,int len){
    len++;
    if(u==tgt){
        if(len>minlen) return;
        if(len<minlen){
            minlen=len;
            cnt=1;
        }else{
            cnt++;
        }
        return ;
    }
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,tgt,u,len);
    }
    return ;
}

void solve(){
    bool flag=true;
    ans=0;
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++) g[i].clear();
    scanf("%lld",&a[1]);
    if(n==1){
        printf("0\n");
        return ;
    }
    scanf("%lld",&a[2]);
    det=a[2]-a[1];
    for(int i=3;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]-a[i-1]!=det) flag=false;
    }
    if(flag==true){
        solveA();
        return ;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                g[i].push_back(j);
            }else break;
        }
    }
//    for(int i=1;i<=n;i++){
//        for(auto v:g[i]){
//            cout<<v<<" ";
//        }
//        puts("");
//    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            minlen=n+7;
            cnt=0;
            dfs(i,j,0,-1);
            if(cnt==2&&minlen!=n+7) ans++;
        }
    }
    printf("%d\n",ans);
    return ;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        solve();
    }
    return 0;
}
