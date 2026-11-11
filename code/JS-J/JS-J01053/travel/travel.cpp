#include<bits/stdc++.h>
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	std::string s1,s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	int s1a,s1b,s2a,s2b;
	s1a=(s1[0]-'0')*10+s1[1]-'0';
	s2a=(s2[0]-'0')*10+s2[1]-'0';
	s1b=s1[2]-'A';
	s2b=s2[2]-'A';
	if(c1==c2)std::cout << 1;
	else std::cout << 0;
	if(c1==c2&&s1a==s2a)std::cout << 1;
	else std::cout << 0;
	if(c1==c2&&s1a==s2a&&((s1b<3&&s2b<3)||(s1b>2&&s2b>2)))std::cout << 1;
	else std::cout << 0;
	if(c1==c2&&s1a==s2a&&((s1b<3&&s2b<3)||(s1b>2&&s2b>2))&&abs(s1b-s2b)==1)std::cout << 1;
	else std::cout << 0;
	std::cout << '\n';
	return 0;
}
