#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn];
int n , m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);

    int num[m+10] = {0};
    for(int i = 1 ; i <= m ;i++){
        int pos = 1;
        int tmp[maxn];
        for(int j = 1 ; j <= n ; j++){
            if(a[j] == i) continue;
            tmp[pos] = a[j]; pos++;
        }

        tmp[++pos] = i;
        for(int k = 1 ; k <= pos ; k++) a[k] = tmp[k];
        n = pos;

        //差重
        int z[m + 10] = {0};
        for(int k = 1 ; k <= pos ; k++)
            z[tmp[k]] ++;
        for(int k = 1 ; k <= m ; k++)
            if(z[k] != 0) num[k] ++;
    }
    for(int i = 1 ; i <= m; i++)
        printf("%d ",num[i]);

    return 0;
}

