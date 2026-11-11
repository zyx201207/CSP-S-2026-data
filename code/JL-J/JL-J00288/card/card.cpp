#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005], c[1000005], n, m, q, p;
void shou(int x){
    for(int i = 1; i <= q; i++){
        if(b[i] == a[x]){
            q = i;
            return;
        }
    }
}
bool bianli(int x){
    for(int i = 1; i <= q; i++)
        if(b[i] == a[x]) return false;
    return true;
}
void youxi(int x){
    for(int i = x; i <= n; i++){
        if(bianli(i)) b[++q] = a[i];
        else shou(i);
    }
}
void panduan1(int x){
    for(int i = 1; i <= q; i++)
        if(b[i] == x) c[x]++;
}
void panduan(int x){
    for(int i = 1; i <= m; i++)
        panduan1(i);
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        youxi(i);
        panduan(i);
        q = 0;
    }
    for(int i = 1; i <= m ; i++)
        cout << c[i] << ' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
