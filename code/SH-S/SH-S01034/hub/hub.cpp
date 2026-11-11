#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,l,r,mid,pth[1000010],plen,cnt;
bool tag,flg;
vector<int> vec[1000010];
void dfss(int u,int pre,int tgt) {
    pth[++plen]=u;
    if (u==tgt) {
        tag=1;
        return;
    }
    for (int v:vec[u]) if (v!=pre) {
        dfss(v,u,tgt);
        if (tag) return;
    }
    --plen;
}
int maxdis(int u,int p1,int p2) {
    int ans=0;
    for (int v:vec[u]) if (v!=p1&&v!=p2) {
        ans=max(ans,maxdis(v,u,0)+1);
    }
    return ans;
}
int dfs(int u,int pre) {
    int ans=0;
    for (int v:vec[u]) if (v!=pre) {
        int x=dfs(v,u);
        if (x>=mid) ++cnt;
        ans=max(ans,x+1);
    }
    return ans;
}
inline bool check() {
    for (int i=1;i<=n;++i) for (int j=i+1;j<=n;++j) {
        tag=0;
        plen=0;
        dfss(i,0,j);
        flg=1;
        for (int j=2;j<plen;++j) if (maxdis(pth[j],pth[j-1],pth[j+1])+min(j-1,plen-j)>mid) flg=0;
        if (!flg) continue;
        cnt=2;
        dfs(i,pth[2]);
        dfs(j,pth[plen-1]);
        if (cnt<=k) return true;
    }
    return false;
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    for (int _=1;_<=t;++_) {
        cin>>n>>k;
        for (int i=1;i<=n;++i) vec[i].clear();
        for (int i=1;i<n;++i) {
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        l=0;
        r=n;
        while (r-l>1) {
            mid=l+r>>1;
            if (check()) r=mid;
            else l=mid;
        }
        cout<<r<<'\n';
    }
}