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
int n,m,w,a[N];
struct node {
	int id,p,t[40];
	friend bool operator < (const node& x,const node& y) {
		if(x.p!=y.p) {
			return x.p>y.p;
		}
		ROF(i,31,0) {
			if(x.t[i]!=y.t[i]) {
				return x.t[i]>y.t[i];
			}
		}
	}
}b[N];
bool cmp(node x,node y) {
	ROF(i,w,0) {
		if(x.t[i]!=y.t[i]) {
			return x.t[i]>y.t[i];
		}
	}
}
bool cmp1(node x,node y) {
	return x.p>y.p;
}
void solve(int id,int x) {
	b[id].p=0;
	while(x) {
		b[id].p++;
		b[id].t[b[id].p]=(x&1);
		x>>=1;
	}
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n) {
		cin>>a[i];
		b[i].id=i;
		solve(i,a[i]);
	}
	int da=-1;
	sort(b+1,b+n+1,cmp1);
	int u=1;
	FOR(i,2,n) {
		if(b[i].p==b[i-1].p) {
			u++;
		}
		else {
			if(u>=m) {
				w=b[i-1].p;
				break;
			}
			u=1;
		}
	}
	//cout<<w<<'\n';
	sort(b+1,b+n+1,cmp);
	FOR(i,1,m) {
		//cout<<b[i].p<<'\n';
		if(da==-1) {
			da=a[b[i].id];
		}
		else {
			da&=a[b[i].id];
		}
	}
	cout<<da;
	return 0;
} 
