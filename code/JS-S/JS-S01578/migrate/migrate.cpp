#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll qread(){
	bool f = 0;
	ll x = 0;
	char op = 0;
	while(op < '0'||op > '9'){
		if(op == '-')   f = 1;
		op = getchar();
	}
	if(f)   while(op>='0'&&op<='9'){
		x = x*10 + '0' - op;
		op =getchar();
	}
	else while(op>='0'&&op<='9'){
		x = x*10 + op -'0';
		op = getchar();
	}
	return x;
}
ll bd[N];
int c, T;
int n;
ll d;
ll x;
int cnt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out", "w",stdout);
	c = qread(), T = qread();
	while(T--){
		int ans = 0;
		n = qread(), d = qread();
		memset(cnt, 0 , n * sizeof(int));
		for(int i = 0; i < n; i++){
			bd[i] = qread();
			ll d1 = d;		
		}
		for(int i =1; i<n; i++){
			if(bd[i]-bd[0]<=d)	cnt[i]++;
			else break;
		}
		for(int i=0; i<n; i++){
			for(int j = n; j>=0; j--){
				int tmp = cnt[j];
				if(bd[i]-bd[j]>=d)	cnt[j]+=cnt[i];
				if(cnt[j]==2)	ans++;
				if(tmp==2&&cnt[j]==3)	ans--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}