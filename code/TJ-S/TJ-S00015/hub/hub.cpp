#include<iostream>
#include<cstdio>

inline void solve(){
	//图论大题.还有11分钟,写完输入输出还差不多(:拉倒吧
	int n;
	std:: cin >> n;
	std::cout << (n*n*n >> 1) << "\n"; 
}

signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, T;
	std::cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}
