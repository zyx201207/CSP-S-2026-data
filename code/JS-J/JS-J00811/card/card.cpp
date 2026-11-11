#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 300005;
int n,m,a[N],ans[M];
int f[N],lst[M],nxt[N],cnt[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%d",a + i);
    for (int i = 1;i <= n;i++){
        nxt[lst[a[i]]] = i;
        lst[a[i]] = i;
    }
    for (int i = n;i;i--){
        if (!nxt[i]){
            f[i] = i;
            continue;
        }
        f[i] = f[nxt[i]];
    }
    for (int i = 1;i <= n;i++){
        cnt[f[i]]++;
        cnt[f[i + 1]] += cnt[i];
        ans[a[i]] += cnt[i];
    }
    for (int i = 1;i <= m;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}