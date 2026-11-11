#include <bits/stdc++.h>
using namespace std;
const int N=2e5 + 5;
int n,m,cnt[35],ans;
struct node {
    int x,y;
}a[N];
bool cmp(node n1,node n2) {
    return n1.y>n2.y;
}
int r;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i].x);
        a[i].y=a[i].x;
        for(int j=0;j<30;++j) {
            r=a[i].x>>j&1;
            cnt[j]+=r;
        }
    }
    for(int j=0;j<30;++j) {
        if(cnt[j]<m) {
            for(int i=1;i<=n;++i) {
                r=a[i].y>>j&1;
                if(r)a[i].y^=(1<<j);
            }
        }
    }
    sort(a+1,a+1+n,cmp);
    ans=-1;
    for(int i=1;i<=m;++i) {
        if(ans==-1)ans=a[i].x;
        else ans&=a[i].x;
    }
    printf("%d",ans);
    return 0;
}
