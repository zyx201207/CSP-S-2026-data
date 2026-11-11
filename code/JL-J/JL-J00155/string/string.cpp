#include<bits/stdc++.h>
using namespace std;
struct PII{
    int num;
    char c;
}p[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long cnt = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %c", &p[i].num, &p[i].c);
    }
    int l = 0, r = n - 1;
    while( l < r ){
        if( p[l].num == p[r].num ){
            if( p[l].c != p[r].c ) cnt += p[l].num;
            l ++, r --;
        }else if( p[l].num > p[r].num ){
            if( p[l].c != p[r].c ) cnt += p[r].num;
            p[l].num -= p[r].num;
            r --;
        }else{
            if( p[l].c != p[r].c ) cnt += p[l].num;
            p[r].num -= p[l].num;
            l ++;
        }
    }
    printf("%lld", cnt);
    return 0;
}
