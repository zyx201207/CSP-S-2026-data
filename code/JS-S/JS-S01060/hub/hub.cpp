#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e6+6;

int n,K,lim;
vector<int> g[N];
int cnt,mxd[N],ans;

void dfs1(int u,int fa){
    mxd[u]=0;
    for (auto v : g[u]){
        if (v!=fa){
            dfs1(v,u);
            mxd[u]=max(mxd[u],mxd[v]+1);
        }
    }
    if (mxd[u]>=lim) cnt++;
}

void dfs2(int u,int fa,int up){
  //  cout<<u<<":"<<cnt<<endl;
    ans=min(ans,cnt);
    int mx=0,mx2=0;
    for (auto v : g[u]){
        if (v^fa){
            int x=mxd[v]+1;
            if (x>=mx) mx2=mx,mx=x;
            else if (x>=mx2) mx2=x;
        }
    }
    int x=up;
    if (x>=mx) mx2=mx,mx=x;
    else if (x>=mx2) mx2=x;
   // cout<<mx<<"&&&"<<mx2<<endl;
    for (auto v : g[u]){
        if (v^fa){
            int tu=mxd[u],tv=mxd[v];
            if (tv+1==mx) mxd[u]=mx2;
            else mxd[u]=mx;
            if (tv+1==mx) mxd[v]=max(mxd[v],mx2+1);
            else mxd[v]=max(mxd[v],mx+1);
            int tc=cnt;
            if (tu>=lim) cnt--;
            if (tv>=lim) cnt--;
            if (mxd[u]>=lim) cnt++;
            if (mxd[v]>=lim) cnt++;
           // cout<<u<<"->"<<v<<":"<<mxd[u]<<","<<mxd[v]<<endl;
            dfs2(v,u,tv+1==mx?mx2+1:mx+1);
            mxd[u]=tu;
            mxd[v]=tv;
            cnt=tc;
        }
    }
}

int cal(int u,int fa){
    cnt=0;
    dfs1(u,fa);
    ans=cnt;
    dfs2(u,fa,0);
   // cout<<lim<<":"<<u<<","<<fa<<":"<<max(ans,1)<<endl;
    return max(ans,1);
}

bool chk(int mid){
    lim=mid;
    for (int i=1; i<=n; i++){
        for (int j : g[i]){
            if (cal(i,j)+cal(j,i)<=K) return 1;
        }
    }
    return 0;
}

int ccnt(int k,int len){
    return k+len+len-1;
}

void solve(){
    cin>>n>>K;
    bool fl=1;
    int len=(n+1)/2;
    fl&=(n%2==1);
    for (int i=1; i<=n; i++){
        g[i].clear();
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if (i<len) fl&=(u==i && v==i+1);
        else fl&=(u==i-len+1 && v==i+1);
    }
    if (n==K){
        cout<<0<<"\n";
        return;
    }
    int l=-1,r=n+1;
    while (l+1<r){
        int mid=l+r>>1;
        if (fl && n>4000){
            if (ccnt(K/2,mid)+ccnt((K+1)/2,mid)>=len) r=mid;
            else l=mid;
            continue;
        }
        if (chk(mid)) r=mid;
        else l=mid;
    }
    cout<<r<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        solve();
    }
    return 0;
}

/*
- Read the problem statements carefully.
- int/long long/__int128.
- The memory limit: /usr/bin/time -v ./T1
- The time limit.
*/

// world.execute(me);