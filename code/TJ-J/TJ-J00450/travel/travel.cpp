#include <iostream>
#include <string>

int xr_c, xx_c;
int xr_is, xx_is;
std::string xr_s, xx_s;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> xr_c >> xr_s >> xx_c >> xx_s;
	if(xr_c != xx_c){
		std::cout << "0000";
		return 0;
	}
	std::cout << 1;
	for(int i = 0;i < 2;++i){
		xr_is = xr_is * 10 + (xr_s[i] - '0');
		xx_is = xx_is * 10 + (xx_s[i] - '0');
	}
	if(xr_is != xx_is){
		std::cout << "000";
		return 0;
	}
	std::cout << 1;
	
	if(!((xr_s[2] < 'D' && xx_s[2] < 'D') || (xr_s[2] > 'C' && xx_s[2] > 'C'))){
		std::cout << "00";
		return 0;
	}
	std::cout << 1;
	
	std::cout << ((xr_s[2] - xx_s[2] == 1) || (xx_s[2] - xr_s[2] == 1));
	return 0;
}
