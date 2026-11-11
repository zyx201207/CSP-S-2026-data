#include <iostream>

int n, m;
int a[500005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n;
	for(int i = 1;i <= n;++i){
		std::cin >> a[i];
	}
	for(int i = 1;i <= m;++i){
		int cnt = 0, now[500005], used;
		for(int j = i;i <= n;++j){
			for(int k = 1;k <= used;++k)
				if(a[j] == now[k])
					used = k - 1;
			now[used++] = j;
		}
		for(int j = 1;j <= used;i++){
			if(now[j] == i){
				++cnt;
			}
		}
		std::cout << cnt << ' ';
	}
	return 0;
}
