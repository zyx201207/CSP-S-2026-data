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
const int N=2e5+10;
const int MOD=1e9+7;
const ll INF=4e18;
int n,m=0,da=0;
struct node {
	int u;
	char c;
}a[N];
string s;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=" ";
	FOR(i,1,n) {
		cin>>a[i].u>>a[i].c;
		m+=a[i].u;
		FOR(j,1,a[i].u) {
			s+=a[i].c;
		}
	}
	FOR(i,1,m/2) {
		if(s[m-i+1]!=s[i]) {
			da++;
		}
	}
	cout<<da;
	return 0;
} 
