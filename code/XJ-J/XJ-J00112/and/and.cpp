//0947
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
int n,m;
int a[maxn],b[maxn];
int ans=0;

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        b[i]=1;
    }
    for(int j=30;j>=0;j--) {
        int t=1<<j,t2=0;
        for(int i=1;i<=n;i++) {
            if((a[i]&t)!=0)
                t2+=b[i];
        }
        if(t2>=m) {
            ans|=t;
            for(int i=1;i<=n;i++)
                if((a[i]&t)==0)
                    b[i]=0;
        }
    }
    printf("%d",ans);
    return 0;
}