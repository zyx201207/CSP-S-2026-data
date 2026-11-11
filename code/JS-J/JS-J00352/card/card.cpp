#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005];
int last[300005];
int cnt[300005];
bool f[3005];

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(last,0,sizeof(last));
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        last[a[i]] = max(i,last[a[i]]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(!f[a[j]]){
                f[a[j]] = 1;
                cnt[a[j]]++;
            }
            if(last[a[j]] != j){
                j = last[a[j]];
                continue;
            }
        }
        memset(f,0,sizeof(f));
    }
    for(int i = 1;i <= m;i++){
        printf("%d ",cnt[i]);
    }
}
