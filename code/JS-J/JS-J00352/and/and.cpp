#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005];
int ans,cnt[32],maxi;

struct node{
    int val1,val2;
    bool ok = 0;
}s[200005];

inline void pls(int x){
    int i = 1;
    while(x){
        cnt[i++] += x%2;
        x /= 2;
    }
}

inline bool cmp(node x,node y){
    if(x.ok != y.ok)  return (int)x.ok > (int)y.ok;
    return x.val1 > y.val1;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        pls(a[i]);
        s[i].val1 = a[i];
        s[i].val2 = a[i];
    }
    for(int i = 30;i >= 1;i--){
        if(cnt[i] >= m){
            maxi = i;
            break;
        }
    }
    if(maxi == 0){
        printf("0");
        return 0;
    }
    int maxn = pow(2,maxi);
    int minn = pow(2,maxi-1);
    for(int i = 1;i <= n;i++){
        s[i].val1 = s[i].val1%maxn;
        if(s[i].val1 >= minn){
            s[i].ok = 1;
        }
    }
    sort(s+1,s+n+1,cmp);
    ans = s[1].val2;
    for(int i = 1;i <= m;i++){
        ans = ans&s[i].val2;
    }
    printf("%d",ans);
}
