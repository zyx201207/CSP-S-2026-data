#include <bits/stdc++.h>

bool is_left(char x){
	return 'A' <= x and x <= 'C';
}

int main(void){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::string c1,s1,c2,s2;
	std::cin>>c1>>s1>>c2>>s2;
	bool st1=false, st2=false, st3=false, st4=false;
	if (c1 == c2) st1=true;
	if (st1 and s1.substr(0, 2) == s2.substr(0, 2)) st2=true;
	if (st2 and ((is_left(s1[2]) and is_left(s2[2])) or (not is_left(s1[2]) and not is_left(s1[2])))) st3=true;
	if (st3 and (std::abs(s1[2] - s2[2]) == 1)) st4=true;
	std::cout<<st1<<st2<<st3<<st4;
}
