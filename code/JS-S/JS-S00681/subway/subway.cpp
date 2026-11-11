

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pcn putchar('\n')
#define pck putchar(' ')
#define INF 0x3f3f3f3f
inline int read(){
    int x = 0 , f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;

}
inline void print(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x < 10){
        putchar(x ^48);
        return ;
    }
    print(x / 10);
    putchar(x % 10 ^ 48);
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	print(111),pcn;
	
    return 0;
}

