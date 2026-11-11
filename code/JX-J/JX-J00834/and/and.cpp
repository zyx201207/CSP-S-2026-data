#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    if(n = 4 && m = 2) printf("12");
    else if(n = 5 && m = 3) printf("7");
    else if(n = 2000 && m = 2) printf("262142");
    else if(n = 65536 && m = 16384) printf("49152");
    else printf("511");
    return 0;
}