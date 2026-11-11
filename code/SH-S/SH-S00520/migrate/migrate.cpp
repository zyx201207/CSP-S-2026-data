#include<bits/stdc++.h>//
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
inline ll read(){
	ll x = 0,f = 1;
	char c = getchar();
	while(('0' > c || c > '9') && c != '-')c = getchar();
	if(c == '-')f = -1,c = getchar();
	while('0' <= c && c <= '9')x = x * 10 + c - 48,c = getchar();
	return x * f;
}
#define N 306 
ll c,_,n,d,a[N],dis[N][N],typ[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),_ = read();
	while(_--){
		n = read();d = read();
		rep(i,1,n)a[i] = read();
		rep(i,1,n)rep(j,1,n)dis[i][j] = 1e6,typ[i][j] = 0;
		rep(i,1,n){
			rep(j,i + 1,n){
				if(a[i] + d >= a[j]){
					dis[i][j] = typ[i][j] = 1;
					continue;
				}
			}
		}
		rep(i,1,n){
			rep(j,i + 1,n){
				rep(k,i + 1,j - 1){
					if(dis[i][j] > dis[i][k] + dis[k][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
						typ[i][j] = typ[i][k] * typ[k][j];
					}
					else if(dis[i][j] == dis[i][k] + dis[k][j]){
						typ[i][j] += typ[i][k] * typ[k][j];
					}
					typ[i][j] = min(typ[i][j],3ll);
				}
			}
		}
		ll res = 0;
		rep(i,1,n)rep(j,i + 1,n){
			if(typ[i][j] == 2)++res;
		}
		cout << res << endl;
	}
	return 0;
}
/*
观察1
岛屿对的两个路径至多有一个位置不同？
2457
2367
意味着 
2357
也是路径，不行
*/
