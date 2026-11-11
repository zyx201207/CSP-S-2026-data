#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],fa[N],f[N],g[N],ans;
vector<int>e[N];
int read(){
    int k=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        k=k*10+ch-'0',ch=getchar();
    return k*f;
}
int find(int x){
    if(x>a[n]) return n+1;
    else return lower_bound(a+1,a+1+n,x)-a;
}
int query(int l,int r){
    l=find(l),r=find(r+1)-1;
    return r-l+1;
}
void dfs(int x){
    f[x]=0,g[x]=0;
    for(int i:e[x]){
        dfs(i);
        for(int j:e[i]){
            int p1=i-1,p2=i-2;
            ans+=g[j]*query(max(a[p1]+d+1,a[i]+1),min(a[fa[x]],a[i]+d));
            if(j<=p2){
                if(e[j].size()==0||a[i-1]-a[j-1]>d)
                    ans+=(f[j]+1)*query(max(a[p2]+d+1,a[i]+1),min(a[fa[x]],a[p1]+d));
                else
                    ans+=query(max(a[p2]+d+1,a[i]+1),min(a[fa[x]],a[p1]+d));
            }
            int t=query(a[x]-d,a[j]+d);
            if(t==1) f[i]=f[i]+f[j]+1,g[i]=g[i]+g[j];
            else if(t==2){
                if(e[j].size()==0||a[i-1]-a[j-1]>d) g[i]=g[i]+f[j];
                g[i]++;
            }
        }
    }
}
void solve(int l,int r){
    for(int i=l;i<r;i++)
        e[fa[i]].push_back(i);
    dfs(r);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--){
        n=read(),d=read();
        for(int i=1;i<=n;i++)
            a[i]=read();
        for(int i=1;i<=n;i++)
            fa[i]=find(a[i]+d+1)-1;
        ans=0;
        int last=1;
        for(int i=1;i<=n;i++){
            if(fa[i]==i){
                solve(last,i);
                last=i+1;
            }
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)
            e[i].clear();
    }
    return 0;
}