#include<bits/stdc++.h>

using namespace std;

int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch > '9'||ch < '0'){
		if(ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*y;
}

void print(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	char ch = x%10+'0';
	if(x >= 10) print(x/10);
	putchar(ch);
}

int ceshidian;

int n,mxd;
int x[2000005];
int gt[2000005];

bool pd(int l,int r){
	return (l <= ceshidian&&ceshidian <= r);
}

void qwq_ovo(){
	
	n = read(),mxd = read();
	for(int i = 1;i <= n;++ i){
		x[i] = read();
		if(i != 1) x[i] -= x[1];
	}
	x[1] = 0;
	
	int l = 1,r = 1;
	while(l <= n){
		while(r+1 <= n&&x[r+1]-x[l] <= mxd) r++;
		gt[l] = r;
		l++;
	}
	
	for(int i = 1;i <= n;++ i){
		int x = i;
		int ans = 0;
		for(int j = i+2;j <= n;++ j){
			while(gt[x] <= j){
				if(x == gt[x]){
					ans = -1;
					break;
				}
				ans++;
				x = gt[x];
			}
			if(ans == -1) break;
			if(x == j) continue;
		}
	}
	
	print(0);putchar('\n');
	
	for(int i = 1;i <= n;++ i)
		x[i] = gt[i] = 0;
	
	return;
	
}

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ceshidian = read();
	int _ = read();
	while(_--) qwq_ovo(); 
	
	return 0;
	
}
