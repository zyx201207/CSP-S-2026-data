#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int N = 2e6+5;
ll read(){
	ll x=0,f=1;char s=getchar();
	while(!isdigit(s)){
		if (s == '-') f=-1;
		s=getchar();
	}while(isdigit(s)){
		x=x*10ll+s-'0';
		s=getchar();
	}return 1ll*x*f;
}
int n;
ll d;
ll x[N],dis[303][303],tot[303][303];
void solve(){
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) tot[i][j] = tot[j][i] = 500;
		
	
	for(int i=2;i<=n;i++) {
		for(int j=1;j<i;j++) {
			if (x[i] - x[j] <= d) 
				tot[i][j] = tot[j][i] = 1;
		}
	}
	int num = 0;
	for(int i=1;i<=n;i++) {
		for(int j=i-1;j;j--) {
			if (tot[i][j] == 1) continue;
			for(int k=j+1;k<i;k++) {
				if (tot[j][k]+tot[k][i]<tot[i][j]) {
					tot[i][j] = tot[j][i] = tot[j][k] + tot[k][i] ;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=i-1;j;j--) {
			if (tot[i][j] == 1) continue;
			int cnt = 0;
			for(int k=j+1;k<i;k++) {
				if (tot[j][k]+tot[k][i] == tot[i][j]) {
					//printf("%d-->%d-->%d\n",j,k,i);
					cnt ++ ;
				}
			}
			if (cnt == 2) num ++ ;//,printf("<%d,%d>\n",i,j);
		}
	}	
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<i;j++) {
//			printf("[%d,%d]->%d\n",j,i,tot[i][j]);
//		}
//	}
//	printf("%d\n",num);
	
}
void solve1(){
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<i;j++) {
			//dis[i][j] = x[n] - x[1] +1;
			tot[i][j] = tot[j][i] = 500;
		}
//		if (x[i+1] - x[i]<= d &&i<n) {
//			dis[i][i+1] = dis[i+1][i] = x[i+1]-x[i];
//		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=1;j<i;j++) {
			if (x[i] - x[j] <= d) {
				
				tot[i][j] = tot[j][i] = 1;
			}
		}
	}
	int num = 0;
	for(int i=1;i<=n;i++) {
		//int cnt = 0;
		for(int j=i-1;j;j--) {
//			if (x[i] - x[j] <= d) {
//				tot[i][j] = tot[j][i] = 1 ;
//				continue;
//			}
			if (tot[i][j] == 1) continue;
			//printf("<%d,%d>\n",i,j);
			int cnt = 0;
			for(int k=j+1;k<i;k++) {
				
				if (tot[j][k]+tot[k][i] == tot[i][j]) {
					cnt ++ ;
				}
				if (tot[j][k]+tot[k][i]<tot[i][j]) {
					cnt = 1;
					tot[i][j] = tot[j][i] = tot[j][k] + tot[k][i] ;
				}
			}
			if (cnt == 2) num ++ ;//,puts("---");
		}
		
	}

	printf("%d\n",num);
}

void solve2(){
	
	if (d<x[2]-x[1] || d<x[3]-x[1]){
		puts("0");
		return ;
	}
	ll dt = x[2] - x[1] ; 
	
	ll l = (d/dt);
	int num = l + l-1 ; 
	printf("%d\n",n-num);
}

int main(){
	freopen("migrate.in","r",stdin);
//	freopen("CCC.out","w",stdout);
	freopen("migrate.out","w",stdout);
	int c=read(),_=read();
	while(_--) {
		n=read(),d=read();
		for(int i=1;i<=n;i++) {
			x[i]=read();
		}
		//solve();
		if (n<=3) {
			puts("0");
		}else if (c>=13 && c<=14) {
			printf("%d\n",n-3);
		}
		else if (c<=12 && c>=11){
			solve2();
		}else if (c<=6){
			solve1();
		}
	}
	
	
	return 0;
}/*
0 1 
9 2 
1 2 3 4 5 6 7 8 9




*/