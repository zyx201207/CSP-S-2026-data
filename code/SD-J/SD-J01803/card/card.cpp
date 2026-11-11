#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[300010],w[300010];
ll cnt = 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	ll x;
	for(int i = 1;i <= n;++i){
		cin >> w[i];
		if(w[i] != w[i-1]){
			a[w[i]] = ++cnt;
		}
	}
	for(int i = 1;i <= m;++i){
		cout << a[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

