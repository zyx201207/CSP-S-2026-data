#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
namespace zyx_{

ll read(){
	ll x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar('0'+x%10);
	return ;
}
vector<int> g[N];
ll c,T,n,k;
void work1(){
	ll res=(n/2+5-k)/4;
	print(max((ll)0,res));
	putchar('\n');
	return ;
}
int my_main(){
	c=read(); T=read();
	while(T--){
		n=read(); k=read();
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			ll u,v;
			u=read(); v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==0||c==13||c==14) work1();
	}
	return 0;
}

}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	zyx_::my_main();
	return 0;
}
