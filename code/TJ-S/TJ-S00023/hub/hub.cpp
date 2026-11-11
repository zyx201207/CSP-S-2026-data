#include <iostream>
#include <vector>
#include <cmath>

struct pos{
	int id;
	std::vector<pos*> ways;
	pos(int d){
		id=d;
	}
};

struct pair{
	int a,b;
};

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int c,t;
	std::cin >> c >> t;
	for(int uwp=1;uwp<=t;uwp++){
		if(13<=c&&14>=c){
			k=k/2;
			n=n/2;
			while(k--)
				n=std::ceil(n/2.0);
			std::cout << n << std::endl;
			continue;
		}
		int n,k;
		std::cin >> n >> k;
		std::cout << __builtin_ctz(k)-__builtin_ctz(n) << std::endl;
	}
}