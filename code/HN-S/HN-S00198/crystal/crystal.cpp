#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N] , b[N];
int n,m;
void solveA() {
	ll sum= 0;
	for(int i=1; i<=n; i++) {
		if(sum + a[i] == m) {
			cout<<i+1;
			return ;
		} else if(sum + a[i]>m) {
			cout<<i;
			return ;
		}
		sum += a[i];
	}
}

void solveB() {
	ll x;
	if(a[2] - a[1] > 0)  x = a[2] - a[1] ;
	else x =  a[1] - a[2] ;
	ll sum= 0;
	if(m<=1) {
		cout<<1;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(sum + i*x == m) {
			cout<<i+1;
			return ;
		} else if(sum + i*x>m) {
			cout<<i;
			return ;
		}
		sum += i*x;
	}

}

int main() {
	freopen("crystal.in", "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	bool A = 0 , B= 0;
	for(int i= 1 ; i<=n ; i++) {
		cin>>a[i];
		if(i>=2) {
			if(a[i] - a[i-1] == 1) A = true;
			else A = false;
		}
		if(i >= 3) {
			if(a[i]- a[i-1] == a[i-1] - a[i-2]) B = true;
			else B = false;
		}
	}
	if(A) {
		solveA();
		return 0;
	}
	if(B) {
		solveB();
		return 0;
	}

	sort(a+1 , a+1+n);

	ll sum = 0;
	ll ans = 0;
	int l = 1 , r= 2;
	while(r<n) {
		ll zz = a[r] -a[r-1];
		while(sum + (r-l)*zz > m) {
			sum -= a[r-1]-a[l];
			l++;
			if( l >= r ) r = l;
			if(r>n) break;
		}
		sum += (r-l) * zz;
		ll len = r - l+1;
		ans = max(len , ans);
		r++;
//		cout<<"l: " <<l <<"  r: "<<r<<"  sum: " <<sum<<"  ans:"<<ans<<"\n";
	}
	cout<<ans;


	return 0;
}










