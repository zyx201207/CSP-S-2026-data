#include<bits/stdc++.h>

#define ll long long
#define ris(x,y,z) for(ll x=y;x<z+1;++x)
#define ful(x,y,z) for(ll x=y;x>z-1;--x)
#define riso(x,y,z,a) for(ll x=y;x!=a;x=z)
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

using namespace std;

const ll N=5e5+5;

ll c,n,m,d,q;

signed main(){
	fre("subway");
	ios::sync_with_stdio(0);
	cin.tie(0),
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	ris(i,1,q)
		cout<<rand()%n<<'\n';
	return 0;
} 
