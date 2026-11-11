#include<iostream>
std::string c1,s1,c2,s2; 
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::cin >> c1 >> s1 >> c2 >> s2;
	int a = c1 == c2,
		 b = a && (s1[0] == s2[0] && s1[1] == s2[1]),
		 c = b && (!(s1[2] == 'C' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'C')),
		 d = c && (s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D' || (s1[2] - s2[2]) == 1 || (s1[2] - s2[2]) == -1);
	std::cout << a << b << c << d;
	return 0;
}
