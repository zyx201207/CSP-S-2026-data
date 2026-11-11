#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans = 0;
int a[200010],b[200010],c[200010];
void dfs(int row){
    if(row > m){
        long long sum = c[1];
        for(int i = 2;i < row;i++){
            sum = sum & c[i];
        }
        ans = max(ans,sum);
        return;
    }
    for(int i = row;i <= n;i++){
        if(b[i] == 0){
            b[i] = 1;
            c[row] = a[i];
            dfs(row + 1);
            b[i] = 0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}
