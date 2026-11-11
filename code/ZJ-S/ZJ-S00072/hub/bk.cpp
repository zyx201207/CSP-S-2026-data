#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=1e5+5;
int n,k,dep[N],x;
vector<int>e[N];
struct A{
    int fu,fv,fl,ft,l,du,dv,dl,t;
}dp[N][2];
A operator+(A a,A b){
    A ans;
    if(a.du+b.du+1>a.l&&a.du+b.du+1>b.l){
        ans.fu=a.fu+max(a.fl,a.dv-x)+a.ft-a.t;
        ans.fv=b.fv+max(b.fl,b.dv-x)+b.ft;
        ans.fl=ans.ft=ans.t=a.t;
        ans.l=a.du+b.du+1;
        ans.du=a.du,ans.dv=b.du+1;
        ans.dl=0;
        if(ans.du<ans.dv){
            swap(ans.du,ans.dv);
            swap(ans.fu,ans.fv);
        }
    }else if(a.l>b.l){
        ans=a;
        ans.fl=max(a.fl,a.dl+b.du+1-x);
        ans.t=max(a.t,b.du+1-x);
        ans.ft=a.ft-a.t+ans.t;
    }else{
        ans=b;
        ans.du++,ans.dv++,ans.dl++;
        ans.fl=max(b.fl,b.dl+1+a.du-x);
        ans.t=max(a.t,a.du-x);
        ans.ft=b.ft+ans.t;
    }
    return ans;
}
int calc(A f){return max(1,f.l-x*2)+f.fu+f.fv+f.fl;}
void dfs1(int p,int f){

}
void dfs2(int p,int f){
    
}
bool check(int x){
    ::x=x;
    // qing kong
    dfs1(1,0),dfs2(1,0);
    int ans=calc(dp[1][0]);
    for(int i=1;i<=n;i++){
        for(int x:e[i])if(dep[x]<dep[i]){
            ans=min(ans,calc(dp[i][0])+calc(dp[i][1]));
        }
    }
    return ans<=k;
}
void _main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1,x,y;i<n;i++)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
    int l=0,r=n;
    while(l<r){
        const int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<r<<'\n';
}
signed main(){
    clock_t _st=clock();
#ifndef LOCAL
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t=1;cin>>c>>t;
    while(t--)_main();
    clock_t _ed=clock();
    cerr<<(_ed-_st)*1.0/CLOCKS_PER_SEC<<'\n';
    return 0;
}
/*
g++ hub.cpp -o hub -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ hub.cpp -o hub -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ hub.cpp -o hub -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ hub.cpp -o hub -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/