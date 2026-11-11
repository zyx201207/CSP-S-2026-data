#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using std::cin; using std::cout;
using std::queue; using std::priority_queue; 
using std::map; using std::set;
using std::string;

const int maxn=220000;

int n;
int a[maxn];
char c[maxn];
long long ans=0;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::cin>>n;
    for(int i=1;i<=n;i++) {
        std::cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<j;) {
        int min=std::min(a[i],a[j]);
        a[i]-=min; a[j]-=min;
        if(c[i]!=c[j])
            ans+=min;
        if(a[i]==0)
            i++;
        if(a[j]==0)
            j--;
    }

    printf("%lld",ans);
    return 0;
}