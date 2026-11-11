#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define sec second

using namespace std;

using ll = long long;
using ull =unsigned long long;
using i128 = __int128;
using p_q =priority_queue<int>;

namespace fenwick{

const int N = 114514;

ll fwk[N];
int n;

void ta(int u,ll k){
	for(;u<=n;u+=u&-u){
		fwk[u]+=k;
	}
}

ll ts(int u){
	ll ans=0;
	for(;u;u-=u&-u) ans+=fwk[u];
	return ans; 
}

ll tq(int l,int r){
	return ts(r)-ts(l-1);
}


}

namespace sharweek{


void mian(){
	system("fc migrate.out migrate6.ans");
}

}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _=1;
	//cin>>_;
	while(_-->0){
		sharweek::mian();
	}
	
	return 0;
} 
