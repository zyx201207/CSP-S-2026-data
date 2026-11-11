#include<bits/stdc++.h>
using namespace std;
const int maxn = 2222222;
long long read(){
	char c = getchar();
	int f = 1;
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	
	long long ans = 0;
	while('0' <= c && c <= '9'){
		ans = ans*10 + c - '0';
		c = getchar();
	}
	ans = ans*f;
	
	return ans;
}
int n;
long long d;
long long x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
//	scanf("%d%d",&c,&t);
	c = read(),t = read();
//	cout << c << ' ' << t << '\n';
	if(1 <= c && c <= 2){
		
	}
	else if(11 <= c && c <= 12){
		while(t--){
//			scanf("%d%lld",&n,&d);
			n = read(),d = read();
			for(int i = 1;i <= n;i++){
//				scanf("%lld",&x[i]);
				x[i] = read();
			}
			long long cha = x[n] - x[n-1];
//			cout << n << ' ' << d << ' ' << cha << ' ' << x[n] << ' ' << x[1] << '\n';
			if(n == 1 || d <= cha){
				cout << 0 << '\n';
			}
			else{
				d = d/cha * cha;
				long long len = d*2-cha;
				if(len > x[n]-x[1]){
					cout << 0 << '\n';
				}
				else{
					long long num = len/cha;
					cout << max(n-num,0ll) << '\n';
				}
			}
		}
	}
	return 0;
}
