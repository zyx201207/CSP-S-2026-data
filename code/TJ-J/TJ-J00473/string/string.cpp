#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std; 
const int N = 2e5+5;
ll ans;
struct node{
	ll v;
	ll c;
};
vector<node> a(N);
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin >> n;
	for(ll i = 1;i<=n;i++){
		cin >> a[i].v >> a[i].c;
	}ll l = 1,r = n;
	while(l<r and l>=1 and l<=n and r>=1 and r<=n){
		if(a[l].c == a[r].c and a[l].v == a[r].v){
			l++;
			r--;
			continue;
		}
		if(a[l].c != a[r].c){
			ans++;
		}
		a[l].v--;
		a[r].v--;
		if(a[l].v <= 0) l++;
		if(a[r].v <= 0) r--;
		
	}cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

