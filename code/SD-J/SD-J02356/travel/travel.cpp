#include<iostream>
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::string c1, s1, c2, s2;
	std::cin>>c1>>s1>>c2>>s2;
	std::string ans;
	ans+=c1==c2?'1':'0';
	ans+=c1==c2 and s1[0]==s2[0] and s1[1]==s2[1]?'1':'0';
	ans+=c1==c2 and s1[0]==s2[0] and s1[1]==s2[1] and (s1[2]<='C' and s2[2]<='C' or s1[2]>'C' and s2[2]>'C')?'1':'0';
	ans+=c1==c2 and s1[0]==s2[0] and s1[1]==s2[1] and (s1[2]<='C' and s2[2]<='C' or s1[2]>'C' and s2[2]>'C') and abs(s1[2]-s2[2])==1?'1':'0';
	std::cout<<ans; 
	return 0;
}
