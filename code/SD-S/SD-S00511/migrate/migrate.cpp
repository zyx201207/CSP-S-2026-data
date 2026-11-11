#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for(int i = (a);i<=(n);++i)
#define ll long long
#define ill __int128

using namespace std;

template<typename T>inline void read(T &x){
	char c = getchar();
	short int t = 1;x = 0;
	for(;!isdigit(c);c = getchar())if(c == '-')t=-1;
	for(;isdigit(c);c = getchar())x = (x<<1) + (x<<3) + (c^48);
	x*=t;
}
template<typename T>inline void write(T x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x >= 10){
		write(x/10);
	}
	putchar(x % 10 + '0');
}
const int N = 1e6 + 10,M = 5e3 + 10;
int c = 0,n = 0,m = 0,T = 0;
ill d = 0;
ill dp[M][M];
ill x[N];
ill get(int a,int b){
	return labs(x[b] - x[a]);
}
bool check(int x){
	int a = x - 3,b = x-2,c = x-1,dd = x;
	if(get(a,c) <= d && get(b,dd) <= d && get(a,dd) > d){
		return 1;
	}
	return 0;
}

void sol1(){
	read(n);read(d);
	rep(i,1,n){
		read(x[i]);
	}	
	cout <<0<<endl;
}
void sol2(){
	read(n);read(d);
	rep(i,1,n){
		read(x[i]);
	}

	int ans = 0;
	
	for(int i = 1;i<=n;++i){
		for(int j = i+1;j<=n;++j){
			int cnt = 0;
			for(int k = i+3;k<=j;++k){
				if(check(k)){
					++cnt;
				}
//				cout <<i<<" "<<j<<" "<<cnt<<endl;
			}
			if(cnt == 1){
				++ans;
			}
		}
	}		
	cout <<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	read(c);read(T);
	while(T--){
		if(c == 13 || c == 14){
			sol1();
			continue;
		}
		if(c <= 10){
			sol2();
		}
				
	}


	return 0;
}
/*
离考试结束还有 1H，写 24 分暴力。 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
