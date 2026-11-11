#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int f,c;
int readint(){
	int k = 0;
	f = 1,c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-')f = -1;
	for(;isdigit(c);c = getchar()) k = k * 10 + (c - '0');
	return k * f;
}

ll readll(){
	ll k = 0;
	f = 1,c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-')f = -1;
	for(;isdigit(c);c = getchar()) k = k * 10 + (c - '0');
	return k * f;
}


int len,l,r,lft,rit,i;
int n;
ll m;
ll a[500005];
ll b[500005];
ll ind[500005];
ll indlen = 0;

ll ans = 0;

ll getene(int l, int r){
	return b[r] - b[l] - (a[r] - a[l]) * (l-1);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = readint(), m = readll();
	for(int i = 1;i <= n;++i){
		a[i] = readll();
	}
	
	sort(a+1,a+1+n);
	
	for(int i = 1;i <= n;++i){
		if(a[i] != a[i+1])ind[++indlen] = i;
		if(a[i] == a[i-1]){
			b[i] = b[i-1];
		}
		else b[i] = (a[i] - a[i-1]) * (i-1) + b[i-1];
	}

	
	for(len = indlen;len >= 1;--len){
		for(l = 1;l + len - 1 <= indlen;++l){
			r = l + len - 1;
			lft = ind[l],rit = ind[r];
			if(getene(lft,rit) <= m){
				cout << rit - lft + 1;
				return 0;
			}
		}
	}
	
	cout << 0;
	return 0;
} 
