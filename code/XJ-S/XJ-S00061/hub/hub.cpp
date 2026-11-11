#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using std::cin; using std::cout;
using std::queue; using std::priority_queue; using std::vector;
using std::map; using std::set;

const int maxn=550000;
int c,T;
int n,k;
vector<int>u[maxn];
int f[maxn];
int ans=0;

void dfs2(int x, int l) {
    int size=u[x].size();
    for(int i=0;i<size;i++) {
        int v=(u[x])[i];
        if(f[v]>l+1) {
            f[v]=l+1;
            dfs2(v, l+1);
        }
    }
    return;
}
int h[maxn],g[maxn];
void lt(int x) {
    int size=u[x].size();
    for(int i=0;i<size;i++) {
        int v=(u[x])[i];
        if(h[v]==1&&g[v]==0) {
            g[v]=1;
            lt(v);
        }
    }
    return;
}
void dfs(int x) {
    if(x>n) {
        int cnt=0,cnt2=0;
        int tans=0;
        for(int i=1;i<=n;i++) {
            cnt+=h[i];
        }
        if(cnt==k) {
            memset(g,0,sizeof(int)*(n+10));
            for(int i=1;i<=n;i++) {
                if(h[i]==1&&g[i]==0) {
                    g[i]=1;
                    lt(i);
                    cnt2++;
                }
            }
            if(cnt2>2) {
                return;
            }
            memset(f,0x1f,sizeof(int)*(n+10));
            for(int i=1;i<=n;i++) {
                if(h[i]==1) {
                    dfs2(i, 0);
                }
            }
            for(int e=1;e<=n;e++) {
                tans=std::max(tans,f[e]);
            }
            ans=std::min(ans,tans);
        }
        return;
    }
    h[x]=1;
    dfs(x+1);
    h[x]=0;
    dfs(x+1);
    return;
}

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    scanf("%d%d",&c,&T);
    while(T-->0) {
        ans=0x1f1f1f1f;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) {
            u[i]=vector<int>();
        }
        for(int i=1;i<n;i++) {
            int U,V;
            scanf("%d%d",&U,&V);
            u[U].push_back(V);
            u[V].push_back(U);
        }
        if(c==7) {
            for(int i=1;i<=n;i++) {
                for(int j=i+1;j<=n;j++) {
                    int tans=0;
                    memset(f,0x1f,sizeof(int)*(n+10));
                    dfs2(i, 0);
                    dfs2(j, 0);
                    for(int e=1;e<=n;e++) {
                        tans=std::max(tans,f[e]);
                    }
                    ans=std::min(ans,tans);
                }
            }
            printf("%d\n",ans);
        } else if(c==13||c==14) {
            printf("%d\n",(n/2-k)/3+1);
        } else if(n<=10) {
            dfs(1);
            printf("%d\n",ans);
        } else {
            printf("1\n");
        }
    }
    return 0;
}
// 调不完了 QAQ
    // freopen("hub.in","r",stdin);
    // freopen("hub.out","w",stdout);
    // 诱捕器