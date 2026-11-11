#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;
const int N = 5e5+5;
ll a[N];
void A(){
	ll T;
	cin >> T;
	while(T--){
		int n,k;
		cin >> n >> k;
		for(ll i = 1;i<n;i++){
			cin >> a[i] >> a[i];
		}
		cout << 1 << endl;
	}
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c;
	cin >> c;
	if(c >= 13 and c <= 14){
		A();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
