#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 5e5+ 10,M = 3e5 + 10;
int a[N],d[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;++ i){
        scanf("%d",&a[i]);
    }
    for (int i = 0;i < n;++ i){
        vector<int> f(m + 10,0),p(n + 10);
        int head = 0;
        for (int j = i;j < n;++ j){
            if (f[a[j]] == 0){
                ++ f[a[j]];
                p[head ++] = a[j];
                continue;
            }
            while (p[head - 1] != a[j]){
                -- f[p[head - 1]];
                -- head;
            }
        }
        for (int j = 0;j < head;++ j){
            if (f[p[j]] == 0) continue;
            ++ d[p[j]];
            f[p[j]] = 0;
        }
    }
    for (int i = 1;i <= m;++ i){
        printf("%d ",d[i]);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
