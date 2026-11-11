#include<bits/stdc++.h>
using namespace std;

vector<int> a[1000005];
int n,m,rt,d[1000005],h[1000005],mh[1000005],k;
void dfs1(int u,int f) {
    mh[u]=0;
    int v;
    for(int i=0;i<a[u].size();i++) {
        v=a[u][i];
        if(v==f) continue;
        h[v]=h[u]+1;
        dfs1(v,u);
        mh[u]=max(mh[u],mh[v]+1);
    }
}
int dfs2(int u,int f,int c,int hf,bool bf) {
    if(hf>k) return 1e7;
    if(hf<=k&&mh[u]<=k&&(bf||c>=1)) return 1;
    long long ans=1e7;
    long long sum=0;
    long long s0,m11=0,m12=0,m2=0;
    int v;
    for(int i=0;i<a[u].size();i++) {
        v=a[u][i];
        if(v==f) continue;
        s0=dfs2(v,u,0,hf+1,0);
        if(c>=1) {
            m12=max(m12,s0-dfs2(v,u,1,hf+1,0));
            if(m12>m11) swap(m12,m11);
        }
        if(c>=2) m2=max(m2,s0-dfs2(v,u,2,hf+1,0));
        sum+=s0;
    }
    ans=sum;
    if(c>=1) ans=min(ans,sum-m11);
    if(c>=2) ans=min(ans,min(ans-m2,ans-m11-m12));
    if(!bf&&c==0) return ans;
    c=c-1+bf;
    sum=1;
    for(int i=0;i<a[u].size();i++) {
        v=a[u][i];
        if(v==f) continue;
        s0=dfs2(v,u,0,-k,1);
        sum+=s0;
        m11=max(m11,s0-dfs2(v,u,1,-k,1));
    }
    if(c>=1) ans=min(ans,sum-m11);
    return ans;
}
bool check(int mid) {
    k=mid;
    return dfs2(rt,0,2,0,0)<=m;
}
void work() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        a[i].clear();
        d[i]=0;
    }
    int u,v;
    for(int i=1;i<n;i++) {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    for(int i=1;i<=n;i++) {
        if(d[i]==1) {
            rt=i;
            break;
        }
    }
    h[rt]=1;
    dfs1(rt,0);
    int l=1,r=n,mid;
    while(l<r) {
        mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--) work();
    return 0;
}