#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],f[2005][2005],c[30];
bool check(int x){
    for(int i = 1;i <= 30;++i)
        if(x == c[i] - 1)
            return true;
    return false;
}
bool check2(int x){
    for(int i = 0;i <= 30;++i)
        if(x == c[i])
            return true;
    return false;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i <= 30;++i)
        c[i] = 1 << i;
    bool ok1 = true;
    bool ok2 = true;
    if(!check2(n))
        ok2 = false;
    for(int i = 1;i <= n;++i)
        if(a[i] != i - 1)
            ok2 = false;
    if(m == 1 || ok2){
        sort(a + 1,a + n + 1,greater<int>());
        int ans = a[1];
        for(int i = 2;i <= m;++i)
            ans &= a[i];
        printf("%d\n",ans);
        return 0;
    }
    for(int i = 0;i <= n;++i)
        f[i][0] = c[30] - 1;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            f[i][j] = max(f[i - 1][j],f[i - 1][j - 1] & a[i]);
            //printf("%d ",f[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",f[n][m]);
}
