//1009~1038
//1044
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

const int maxn=550000;
int n,m;
int a[maxn],last[maxn],next[maxn];
int flag[maxn];
int cnt[maxn];
int ans[maxn];

int main() {
    // freopen("card.in","r",stdin);
    // freopen("card.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        next[last[a[i]]]=i;
        last[a[i]]=i;
        cnt[i]=1;
    }
    // for(int i=1;i<=n;i++) {
    //     if(flag[i]==1)
    //         continue;
    //     int flagB=1;
    //     for(int j=i,k=1;j<=n;) {
    //         if(flag[j]==1) {
    //             k-=flagB;
    //             flagB=0;
    //         }
    //         flag[j]=1;
    //         if(next[j]!=0) {
    //             j=next[j];
    //             k+=flagB;
    //         } else {
    //             ans[a[j]]+=k;
    //             j++; k+=flagB;
    //         }
    //     }
    // }
    for(int i=1;i<=n;i++) {
        if(next[i]!=0) {
            cnt[next[i]]+=cnt[i];
        } else {
            cnt[i+1]+=cnt[i];
        }
    }
    for(int i=1;i<=n;i++)
        ans[a[i]]=std::max(ans[a[i]],cnt[i]);
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    return 0;
}