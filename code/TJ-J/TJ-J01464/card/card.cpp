#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin >> n >>m;
	ll a[n+3];
	for (int i = 1; i <= n; i++){
		cin>> a[i];
	}	
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (f[a[j]]==1){
				
			}
			f[a[j]]=1;
		}
	}
	return 0;
}
