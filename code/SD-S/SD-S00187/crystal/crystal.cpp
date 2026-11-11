#include<bits/stdc++.h>
#include<iomanip>
#define ll long long
using namespace std;
const int N = 5e5+5;

ll n ,m ,ans;
ll l = 1 ,r = 1 ,maxn ,minn;

struct node{
	ll x;
	ll p;
} a[N]; 

bool cmp(node x, node y) {
	return x.x < y.x;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if( n==1 ) {
		cout << 1;
		return 0;
	}
	for(int i=1; i<=n ; i++) {
		cin >> a[i].x;
		minn = min(minn , a[i].x);
	}
	sort(a+1 ,a+1+n ,cmp);
	if( m==0 ) {
		ll k = 1;
		bool f = false;
		for(int i=1; i<=n ; i++) {
			if( a[i].x==a[i-1].x ) k++;
			else{
				f = true;
				maxn = max(maxn ,k);
				k=1;
			}
		}
		cout << max(maxn , k);
		return 0;
	}
	for(int i=1; i<=n;  i++) {
		if( minn < 0 ) a[i].x+=abs(minn)+1;
		a[i].p = a[i-1].p + a[i].x;
	}
	while( l<=r && r<=n ){
		maxn = max( maxn , r-l+1 );
		if( (r-l+1)*a[r].x-a[r].p+a[l-1].p <= m ) r++;
		else l++ ;
	}
	cout << maxn-1;
	return 0;
}
