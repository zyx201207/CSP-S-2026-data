#include<bits/stdc++.h>
using namespace std;
#define fr first
#define se second
const int N = 2e6 + 5;
long long n,d,c,t,x[N],ne[N],bn[N][25],ans;

pair<short,short> tx[N],bt[N][25],cs;
void cl(int i){

    int l1 = i+1,r1 = ne[i],l2 = ne[i]+1,r2 = ne[ne[i]],t1,t2,k;
    if(l2>r2){
        t1 = 0;t2 = 0;
    }
    else if(l2==r2){
        t2 = 0;
    }
    else{
        k = lower_bound(x+1,x+n+1,x[r2-1] - d) - x;
        t2 = r1 - max(l1,k) + 1;
    }
    k = lower_bound(x+1,x+n+1,x[r2] - d) - x;
    t1 = r1 - max(l1,k) + 1;
    t1 = min(t1,3);
    t2 = min(t2,3);
    tx[i] = make_pair(t1,t2);
    bt[i][0] = tx[i];
    return ;
}

pair<short,short> hb(pair<short,short> a,pair<short,short> b){
    int t1 = 0,t2 = 0;
    if(b.fr==0){
        t1 = 0;
    }
    else if(b.fr == 1){
        t1 = a.fr;
    }
    else if(b.fr == 2){
        t1 = a.fr + a.se;
    }
    else {
        if(!a.se)t1 = a.fr;
        else t1 = 3;
    }
    if(b.se==0){
        t2 = 0;
    }
    else if(b.se == 1){
        t2 = a.fr;
    }
    else if(b.se==2){
        t2 = a.fr + a.se;
    }
    else {
        if(!a.se)t2 = a.fr;
        else t2 = 3;
    }
    t1 = min(t1,3);
    t2 = min(t2,3);
    return make_pair(t1,t2);
}
void init(){
    for(int i = 1;i<=n;i++){
        ne[i] = upper_bound(x+1,x+n+1,x[i] + d) - x - 1;
        bn[i][0] = ne[i];
    }
    for(int i = 1;i<=21;i++){
        for(int j = 1;j<=n;j++){
            bn[j][i] = bn[bn[j][i-1]][i-1];
        }
    }
    for(int i = 1;i<=n;i++){
        cl(i);
    }
    for(int i = 1;i<=21;i++){
        for(int j = 1;j<=n;j++){
            bt[j][i] = hb(bt[j][i-1],bt[ne[j]][i-1]);
        }
    }
    return ;
}

bool check(int l,int r){
    if(ne[l]>=r)return 0;
    int t1 = 0,t2 = 0,u;
    if(ne[l]>=l+1){
        t1 = 1;
    }
    if(ne[l]>l+1)t2 = 1;

    u = l;
    cs.fr = t1,cs.se = t2;
    for(int i = 21;i>=0;i--){
        if(ne[bn[u][i]] < r){
            cs = hb(cs,bt[u][i]);
            u = bn[u][i];
        }
    }
   // cout<<cs.fr<<' '<<cs.se<<endl;
    int l1 = u+1,r1 = ne[u],r2 = r,k;

    k = lower_bound(x+1,x+n+1,x[r2] - d) - x;
    t1 = r1 - max(l1,k) + 1;
    t1 = min(t1,3);

    if(t1 == 1){
        t1 = cs.fr;
    }
    else if(t1 == 2){
        t1 = cs.fr + cs.se;
    }
    else if(t1>2){
        if(!cs.se)t1 = cs.fr;
        else t1 = 3;
    }
    return (t1==2);
}
void solve(){
    scanf("%lld%lld",&n,&d);
    for(int i = 1;i<=n;i++)scanf("%lld",&x[i]);
    init();
    ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            ans += check(i,j);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        solve();
    }
    return 0;
}
