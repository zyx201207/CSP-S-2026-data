#include <bits/stdc++.h>

std::string c1,s1,c2,s2;

inline bool check(){
	return (s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'));
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		std::cout<<1;
	else
		std::cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))
		std::cout<<1;
	else
		std::cout<<0;
	int n1=s1[2]-'A'+1,n2=s2[2]-'A'+1;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((n1<=3&&n2<=3)||(n1>3&&n2>3)))
		std::cout<<1;
	else
		std::cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&check())
		std::cout<<1;
	else
		std::cout<<0;
	std::cout<<"\n";
	return 0;
}
