#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) ((x)&(-x))
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef long long ll;
const int N=1e5+10;
const int MOD=1e9+7;
const ll INF=4e18;
string a,b,a1,b1;
bool f,f1,f2,f3;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	f=false,f1=false,f2=false,f3=false;
	if(a==b) {
		f=true;
	}
	if(f&&a1.substr(0,2)==b1.substr(0,2)) {
		f1=true;
	}
	if(f&&f1&&((a1[2]<='C'&&b1[2]<='C')||(a1[2]>'C'&&b1[2]>'C'))) {
		f2=true;
	}
	if(f&&f1&&f2) {
		if(a1[2]=='A'&&b1[2]=='C'||a1[2]=='C'||b1[2]=='A') {
			f3=false;
		}
		else {
			f3=true;
		}
	} 
	cout<<f<<f1<<f2<<f3;
	return 0;
} 
