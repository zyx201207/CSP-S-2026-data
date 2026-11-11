#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5  + 10;
ll a[N]; 
ll n,m;
bool b[N];
ll ans;

ll coun(int n){
	int ans = 0;
	while(n){
		n/=2;
		ans ++;
	}
	return ans;
}

void check(ll an){
	if(an > m){
		cout << ans;
		return ;
	}
	ll maxm = 0,max1;
	for(ll i = 1;i <= n;i++){
		int n1 = ans & a[i];
		if(n1 > maxm && b[i] == false){
			maxm = n1;
			max1 = i;
		}
	}
	ans = ans & a[max1];
	//cout << "\n" << ans << ' ' << a[max1];
	b[max1] = true;
	check(an + 1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);

	if(m == 1) cout << a[n];
	else{
		bool f = false;
		for(int i = 0;i < n;i++){
			if(coun(a[n - i]) == coun(a[n - i - 1])){
				ans = a[n - i];
				b[n - i] = true;
				f = true;
				break;
			}
		}
		if(f == false){
			ans = a[n];
			b[n] = true;
		}
		//cout << a[n] << ' ';
		//cout << ans << ' ';
		check(2);
		
	}
	return 0;
}
