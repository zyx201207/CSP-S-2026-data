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

const int N = 5e5 + 10;
int n , m;
int a[N] , yqwssum[N];
inline bool yqwscheck(int l , int r){
	if(a[r] * (r - l) - (yqwssum[r] - yqwssum[l]) > m){
		return false;
	}
	else {
		return true;
	}
}
inline int yqwsfid(int x){
	int l = 0 , r = x+ 1;
	int ret = 1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(!yqwscheck(mid,x)){
			l = mid + 1;
		}
		else if(yqwscheck(mid,x)){
			r = mid;
			ret = x - mid;
		}
	}
	return ret;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	n = read() , m = read();
	for(int i = 1 ; i <= n; i++){
		a[i] = read();
	}
	sort(a + 1 , a + n + 1 );
	int ans = 0;
	for(int i = 1 ; i <= n; i++){
		yqwssum[i] = yqwssum[i-1] + a[i];
		int nowans = yqwsfid(i);
		ans = max(ans , nowans);
	}
	print(ans),pcn;
	
    return 0;
}


