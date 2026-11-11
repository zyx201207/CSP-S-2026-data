#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = 0;
ll maxn;

ll n,m,i,l;
ll a[200005];

bool cmp(ll x, ll y){
	return x > y;
}

ll k;
int f, c;
ll readll(){
	k = 0,f = 1,c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c = getchar()) k = k * 10 + (c - '0');
	return k * f; 
}

int main(){
	freopen("and.in ","r",stdin);
	freopen("and.out ","w",stdout);
	n = readll();
	m = readll();
	for(i = 1;i <= n;++i){
		a[i] = readll();
	}
	sort(a+1,a+1+n,cmp);
	for(l = 0;l+m <= n;++l){
		maxn = 1073741823;
		for(i = 1;i <= m;++i){
			maxn &= a[l+i];
			if(maxn == 0)break;
			if(maxn < ans)break;
		}
		ans = max(ans,maxn);
	}
	cout << ans;
	return 0;
}

