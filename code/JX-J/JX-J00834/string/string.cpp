#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m = 0;
char ch;
ll ans = 0, k = 0, l = 0;
char s[100000];
struct Str{
    ll a;
    char c;
}scn, rdo[200000];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%c%c%c", &scn.a, &ch, &scn.c, &ch);
        l += scn.a;
        if(m != 0 && scn.c == rdo[m - 1].c) rdo[m - 1].a += scn.a;
        else rdo[m].a = scn.a, rdo[m++].c = scn.c;
    }
    if(m == 1){
        printf("0");
        return 0;
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < rdo[i].a; j++)
            s[k] = rdo[i].c, k++;
    for(int i = 0; i * 2 + 1 < l; i++){
        if(s[i] != s[l - i - 1]) ans++;
    }
    printf("%lld", ans);
    return 0;
}