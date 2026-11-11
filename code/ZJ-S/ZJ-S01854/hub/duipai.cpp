#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }

int main(){
	int T = 100;
	for(int i=1;i<=T;i++){
		assert(!system("./gen"));
		assert(!system("./brute"));
		assert(!system("./hub"));
		if(system("diff -Zq hub.out hub.ans")){
			cerr<<"WA on "<<i<<endl;
			exit(0);
		}else
			cerr<<"AC on "<<i<<endl;
	}
}