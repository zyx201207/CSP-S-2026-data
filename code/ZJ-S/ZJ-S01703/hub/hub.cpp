#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,aa,bb,cc,dd;
void sv_1(){
	while(T--){
		cin>>n>>k;
		cout<<(n+1-k)/8+1<<"\n";
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>c>>T;
	if(c==13||c==14){
		sv_1();
	}
}