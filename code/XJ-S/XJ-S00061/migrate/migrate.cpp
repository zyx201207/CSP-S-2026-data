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

const int maxn=2200000;
int c,T;
long long n,d;
long long x[maxn];
int f[maxn],g[maxn];

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%d%d",&c,&T);
    while(T-->0) {
        long long ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&x[i]);
        }
        if(c==11||c==12) {
            long long drt=x[2]-x[1];
            long long temp=d/drt;
            ans=n-2*temp+1;
            if(ans<0)
                ans=0;
            if(temp<=1)
                ans=0;
        } else if(c==13||c==14) {
            memset(g,0,sizeof(int)*(n+10));
            int R=1,l=1;
            for(;R<=n;R++) {
                if(x[R]-x[1]>d) {
                    break;
                }
            }
            for(;l<=n;l++) {
                if(x[R]-x[l]<=d) {
                    l--;
                    break;
                }
            }
            R--;
            int L=n,r=n;
            for(;L>=1;L--) {
                if(x[n]-x[L]>d) {
                    break;
                }
            }
            for(;r>=1;r--) {
                if(x[r]-x[L]<=d) {
                    r++;
                    break;
                }
            }
            L++;
            if(R-L+1==2) {
                ans=l*r;
            }
        } else {
            for(int u=1;u<=n;u++) {
                memset(f,0x3f,sizeof(int)*(n+10));
                memset(g,0,sizeof(int)*(n+10));
                f[u]=0; g[u]=1;
                for(int l=u;l<n;l++) {
                    for(int r=l+1;r<=n;r++) {
                        if(x[r]-x[l]>d) {
                            break;
                        }
                        if(f[r]>f[l]+1) {
                            f[r]=f[l]+1;
                            g[r]=0;
                        }
                        if(f[r]==f[l]+1) {
                            g[r]+=g[l];
                        }
                    }
                }
                for(int i=1;i<=n;i++) {
                    if(g[i]==2) {
                        ans++;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}