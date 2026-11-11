#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int rng(int x,int y){ return x+rnd()%(y-x+1); }


void procedure(){
	int n=8,k=rng(2,n);
	cout<<n<<" "<<k<<endl;
	for(int i=2;i<=n;i++)
		cout<<rng(1,i-1)<<" "<<i<<endl;
}
int main(){
	assert(freopen("hub.in","w",stdout));
	int T=10;
	cout<<"0 "<<T<<endl;
	while(T--) procedure();
}