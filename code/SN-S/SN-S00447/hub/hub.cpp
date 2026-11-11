//SN-S00447 陈博煜 西安交通大学附属中学 
#include <iostream>
using namespace std;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

int main(){
	return 0;
}
