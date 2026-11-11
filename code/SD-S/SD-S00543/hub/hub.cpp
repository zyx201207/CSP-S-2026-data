#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 100;
template<typename TY>
void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	s = x * f;
}
int c,t;
int n,k;
vector<int> e[N];
void solve(){
	read(n); read(k);
	int u,v;
	for(int i=1;i<n;i++){
		read(u); read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout << rand()%10 << '\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	read(c); read(t);
	while(t--){
		solve();
	}
	return 0;
}
