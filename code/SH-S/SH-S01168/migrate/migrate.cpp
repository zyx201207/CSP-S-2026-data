#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;
int c,t;
int n;
ll d,x[2000010];
namespace A{
	int f[5010][5010],num[5010][5010];
}
#define gc getchar
int read_int(){
	int val = 0,w = 1;
	char c = gc();
	while(c<'0'||c>'9'){
		if(c=='-') w = -1;
		c = gc();
	}
	while('0'<=c&&c<='9'){
		val = val*10+c-'0';
		c = gc();
	}
	return val*w;
}
ll read_ll(){
	ll val = 0,w = 1;
	char c = gc();
	while(c<'0'||c>'9'){
		if(c=='-') w = -1;
		c = gc();
	}
	while('0'<=c&&c<='9'){
		val = val*10+c-'0';
		c = gc();
	}
	return val*w;
}
void write_ll(ll x){
	static int a[60],top;
	top = 0;
	if(x<0){
		putchar('-');
		x = -x; 
	}
	do{
		a[++top] = x%10;
		x /= 10;
	}while(x);
	while(top) putchar('0'+a[top--]);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n = read_int();
		d = read_ll();
		for(int i = 1;i <= n;i++) x[i] = read_ll();
		
		if(c<=10){
			using namespace A;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					f[i][j] = n+2;
				}
			}
			ll ans = 0;
			for(int s = 1;s <= n;s++){
				int l = s,r = s;
				f[s][s] = 0;num[s][s] = 1;
				for(int t = s+1;t <= n;t++){
					while(x[t]-x[l]>d) l++;
					if(l==t) break;
					f[s][t] = f[s][l]+1;
					num[s][t] = 0;
					for(int i = l;i < t;i++){
						if(f[s][i]==f[s][l]){
							num[s][t] += num[s][i];
						}
					}
					if(num[s][t]==2) ans++;
				}
			}
			write_ll(ans);
			putchar('\n'); 
		}
		else if(c<=12){
			if(n<=1) cout<<0<<'\n';
			else{
				ll dif = x[2]-x[1];
				ll m = d/dif;
				ll ans = max(0ll,n-2*m+1);
				if(m<=1) ans = 0;
				write_ll(ans);
				putchar('\n');
			}
		}
	}
}
