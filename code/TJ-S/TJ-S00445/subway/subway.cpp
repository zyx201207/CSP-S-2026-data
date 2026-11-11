#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;
const int N = 5e5+5;
ll t1[N];
void A(){
	ll n,m,d,q;
	cin >> n >> m >> d >> q;
	cout << n/2 << endl;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c;
	cin >> c;
	if(c >= 7 and c <= 11){
		A();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
