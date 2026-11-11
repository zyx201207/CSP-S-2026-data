
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

const int N = 2e6 + 10;
int c , t;
int n , d;
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

	c = read() , t = read();
	while(t--){
		memset(a,0,sizeof(a));
		n = read() , d = read();
		for(int i = 1 ; i <= n ;i++){
			a[i] = read();
		}
		if(n == 0 or n == 1){
			print(0),pcn;
			continue;
		}
		if(abs(a[2] - a[1]) <= d){
			
			int now = d / (abs(a[2] - a[1]));
			if(now < 2){
				print(0),pcn;
				continue;
			}
			else{
				print(n - (2 * now) + 1),pcn;
				continue;
			}
			
		}
		else{
			print(0),pcn;
			continue;
		}
	}
    
    return 0;
}

