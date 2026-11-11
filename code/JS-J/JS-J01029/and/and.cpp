#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,g[200005],anss = 0;cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> g[i];
    sort(g+1,g+1+n,cmp);
    anss = g[1];
    for (int i = 2;i <= m;i++){
        anss = anss & g[m];
    }
    printf("%d",anss);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
