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
long long n,m;
long long a[maxn],b[maxn];
int ans=0;

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) {
        b[i]=b[i-1]+a[i];
    }
    for(int l=1,r=1;r<=n;r++) {
        while((a[r]*(r-l+1))-(b[r]-b[l-1])>m) {
            l++;
        }
        ans=std::max(ans,r-l+1);
    }
    printf("%d",ans);
    return 0;
}