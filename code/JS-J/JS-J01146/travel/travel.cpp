#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline int read();
inline void wt(int);
string c1,s1,c2,s2;
bool b1;
bool is3(const char& a,const char& b){
    if(a <= 'C' && b <= 'C') return 1;
    if(a >= 'D' && b >= 'D') return 1;
    return 0;
}
bool is4(const char& a,const char& b){
    if(abs(b - a) == 1 && (max(a,b) != 'D')) return 1;
    if(b == 'D' && a == 'F' || b == 'F' && a == 'D') return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    b1 = (c1 == c2);
    if(b1 == 0) {
        putchar('0'),putchar('0'),putchar('0'),putchar('0');
    }else{
        putchar('1');
        b1 = (s1[0] == s2[0] && s1[1] == s2[1]);
        if(b1 == 0) putchar('0'),putchar('0'),putchar('0');
        else{
            putchar('1');
            b1 = (is3(s1[2],s2[2]));
            if(b1 == 0) putchar('0'),putchar('0');
            else{
                putchar('1');
                b1 = (is4(s1[2],s2[2]));
                if(b1 == 0) putchar('0');
                else putchar('1');
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

inline int read(){
    register int r;register bool f = 1;register char c;
    while((c = getchar()) && !isdigit(c)) if(c == '-') f^=1;
    r = (c ^ 48);
    while((c = getchar()) && isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48);
    return r * (f ? 1 : -1);
}
inline void wt(int n){
    if(n < 0) putchar('-'),n = -n;
    if(n > 9) wt(n / 10);
    putchar(n % 10 + 48);
}
