#include<iostream>
#include<algorithm>
using ll = long long;
ll n,m,a[500010],b[500010][2],tot,mx;
signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		std::cin >> a[i];
	}
	std::sort(a+1,a+n+1);
	b[++tot][0] = a[1],b[1][1] = 1;
	for(ll i = 2;i <= n;i++){
		if(a[i] == a[i-1]) b[tot][1]++;
		else b[++tot][0] = a[i],b[tot][1] = 1;
	}
//	std::cout << tot << std::endl;
	for(ll i = 1;i <= tot;i++){
		ll l = i-1,tmp = m,ans = b[i][1];
//		std::cout << i << ":";
		while(l >= 1){
//			std::cout << l << " ";
			ll dif = b[i][0] - b[l][0];
			if(tmp - dif >= 0){
				if(tmp / dif < b[i][1]){
					ans += tmp / dif;
					break;
				}else{
					ans += b[l][1];
					tmp -= dif * b[l][1];
					l--;
				}
			}else break;
		}
		mx = std::max(mx,ans);
//		std::cout << endl;
	}
	std::cout << mx;
	return 0;
}
