#include<bits/stdc++.h>
#define ll long long
#define in inline
#define get getchar()
using namespace std;
in ll read(){
    ll x = 0 , f = 1;
    char ch = get;
    while(ch < '0' || ch > '9'){
        if(ch = '-') f = -1;
        ch = get;
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = get;
    }
    return x * f;
}
in void print(ll x){
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
ll n , a[20005] , num , l = 1 , r = 1 , maxx , ls1[10005] , rs1[10005] , lnum , rnum , c , d , ans;
char b[200005] , ls2[10005] , rs2[10005];
bool y , z;
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    n = read();
    for(ll i = 1;i <= n;i ++){
        a[i] = read();
        cin >> b[i];
        num += a[i];
    }
    maxx = num / 2;
    y = true;
    z = true;
    for(ll i = 1;i <= n && (z || y);i ++){
        if(z){
            lnum += a[i];
            ls2[i] = b[i];
            if(lnum >= maxx){
                c = lnum - maxx;
                d = a[i] - c;
                ls1[i] = d;
                z = false;
            }
            else ls1[i] = a[i];
        }
        if(y){
            rnum += a[n - i + 1];
            rs2[i] = b[n - i + 1];
            if(rnum >= maxx){
                c = rnum - maxx;
                d = a[n - i + 1] - c;
                rs1[i] = d;
                y = false;
            }
            else rs1[i] = a[n - i + 1];
        }
    }
    while(l <= maxx && r <= maxx){
        if(ls1[l] < rs1[r]){
            rs1[r] -= ls1[l];
            if(ls2[l] != rs2[r]) ans += ls1[l];
            l ++;
        }
        else if(ls1[l] > rs1[r]){
            ls1[l] -= rs1[r];
            if(ls2[l] != rs2[r]) ans += rs1[r];
            r ++;
        }
        else{
            if(ls2[l] != rs2[r]) ans += rs1[r];
            l ++;
            r ++;
        }
    }
    cout << ans;
    return 0;
}