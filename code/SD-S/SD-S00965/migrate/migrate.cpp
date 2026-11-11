#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int testnumber;
inline ll read(){
	int f = 1;
	ll x = 0;char c = getchar();
	while(c < '0'||c > '9'){
		if(c == '-') f = -f;
		c = getchar();
	}
	while(c >= '0'&&c <= '9'){
		x = (x<<1) + (x<<3) + int(c-'0');
		c = getchar();
	}
	return x*f;
}
void write(ll x){
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}
int T;
int n;ll d;
int tp[N];
ll num[N];
ll gs[N];
ll qzh[N];
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	testnumber = read();
	T = read();
	while(T--){
		n = read();d = read();
		ll ans = 0;
		for(int i = 1;i <= n;i++) a[i] = read();
		for(int i = 1;i <= n;i++){
//			memset(tp,0,sizeof(tp));
//			memset(num,0,sizeof(num));
			int pos = i;
			for(int j = i;j <= n;j++){
				while(a[j]-a[pos] > d)num[tp[pos]]-= gs[pos],tp[pos] = 0,gs[pos] = 0,pos++;
				if(i == j) tp[j] = 0,num[tp[j]]++,gs[j] = 1;
				else{
					if(num[tp[pos]] == 2) ans++;
					tp[j] = tp[pos]+1;
					gs[j] = num[tp[pos]];
					num[tp[j]] += gs[j];
				}
			}
			for(;pos <= n;pos++){
				num[tp[pos]]-= gs[pos];
				tp[pos] = 0;
				gs[pos] = 0;
			}
		}
		write(ans);putchar('\n');
	}
	return 0;
}

