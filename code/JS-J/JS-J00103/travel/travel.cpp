#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,k;
inline int read(){
    int x = 0,f = 1;
    char cn = getchar();
    while (!isdigit(cn)){
        cn = getchar();
    }
    while (isdigit(cn)){
        x = (x << 1) + (x << 3) + (cn ^ 48);
        cn = getchar();
    }
    if (cn >= 'A' && cn <= 'F') k = cn - 'A' + 1;
    return x;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    a = read();
    b = read();
    c = k;
    d = read();
    e = read();
    f = k;
    bool p1,p2,p3,p4;
    p1 = p2 = p3 = p4 = 0;
    if (a == d) p1 = 1;
    if (p1 && b == e) p2 = 1;
    if (p2 && ((c <= 3 && f <= 3) || (c >= 4 && f >= 4))) p3 = 1;
    if (p3 && (c - f == 1 || f - c == 1)) p4 = 1;
    cout << p1 << p2 << p3 << p4;
    return 0;
}
