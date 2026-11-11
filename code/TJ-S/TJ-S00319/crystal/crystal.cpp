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

const int N = 5e5+7;
int a[N];

int n;
long long m;

bool check(int x){
	x = n-x;
	return x*(x+1)*(a[2]-a[1])/2 <= m;
}

void solve(){
	n = read();
	m = read();
	for(int i = 1;i <= n;i += 1){
		a[i] = read();
	}
	
	sort(a+1,a+n+1);
	
	bool f = 1;
	for(int i = 3;i <= n;i += 1){
		if(a[i]-a[i-1] != a[i-1]-a[i-2]){
			f = 0;
			break;
		}
	}
	
	if(f == 1){//等差数列下的二分答案解法
		int r = n;
		int l = 1;
		while(l <= r){
			int mid = l + ((r-l) >> 1);
			if(check(mid)){
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		printf("%d",n-r);
		return ;
	}
	
	//5000轻轻松松 
	int ans = -1;
	for(int i = 1;i <= n;i += 1){
		int j = i;
		int ene = 0;//能量 
		while(1){
			j--;
			ene += a[i] - a[j];
			if(ene > m or j == 0){
				ans = max(ans, i-j);
				break;
			}
		}
	}
	printf("%d",ans);
	return ;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
