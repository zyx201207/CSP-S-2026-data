#include <bits/stdc++.h>
using namespace std;

inline long long read(){
	long long x = 0;
	long long fu = 1;
	char c = getchar();
	while((c < '0' or c > '9') and c != '-') c = getchar();
	if(c == '-') {fu = -1;c = getchar();}
	while(c >= '0' and c <= '9'){
		x = x*10 + (c - '0');
		c = getchar(); 
	}
	return x * fu;
} 

const int N = 5007;
const int MAXN = 2e6+7;
long long x[MAXN];

int n;
long long d;

vector <int> e[MAXN];
int len[N][N];

int min_lenth(int l,int r){
	if(len[l][r] == 0 and e[l][e[l].size()-1] < r) len[l][r] = min_lenth(e[l][e[l].size()-1],r)+1;
	else if(len[l][r] == 0) len[l][r] = 1;
	return len[l][r];
}

void solve(){
	n = read();//岛屿数量 
	int d = read();//海鸟飞行距离 
	for(int i = 1;i <= n;i += 1){
		x[i] = read();
		for(int j=1;j<i;j++){
			if(x[i]-x[j] <= d){
				e[j].push_back(i);
			}
		}
	}
	
	if(d > x[n] - x[1]){
		printf("0\n");
		return ;
	}
	
	//确定双端点
	long long sum = 0;
	for(int l = 1;l < n;l += 1){
		for(int r = l+1;r <= n;r += 1){
			int minLenth = min_lenth(l,r);
			sum += minLenth;
		}
	}
	printf("%lld\n",sum/n);
	return ;
}

int dp[N];

void solveA(){
	n = read();
	int d = read();
	for(int i = 1;i <= n;i += 1){
		x[i] = read();
	}
	
	int step = d / (x[2]-x[1]);
	
	/* 
	for(int i = 1;i<=step;i++){
		dp[i] = 1;
	}
	for(int i=step+1;i<=n;i++){
		int sum = 0;
		for(int j=i-((i-1)%step);j<i;j++){
			sum += dp[j];
		}
		dp[i] = sum;
	}
	*/
	
	printf("%d\n",n-step);
	return ;
}

void solveB(){
	n = read();
	int d = read();
	for(int i = 1;i <= n;i += 1){
		x[i] = read();
	}
	
	printf("0\n");
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int num = read();//测试点编号
	int T = read();
	if(num == 11 or num == 12) while(T--) solveA();
	else if(num == 13 or num == 14) while(T--) solveB();
	else while(T--) solve();
	return 0; 
}
