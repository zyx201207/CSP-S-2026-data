#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
bool is_same_side(const char& a ,const char& b)
{
	if((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C'))
		return true;
	if((a == 'D' || a == 'F') && (b == 'D' || b == 'F'))
	    return true;
	else
		return false;
}

int main()
{
	std::freopen("travel.in","r",stdin);
	std::freopen("travel.out","w",stdout);
	std::string c1,s1,c2,s2,ans;
	
	std::cin>>c1>>s1>>c2>>s2;
	(c1 == c2) ? ans += "1" : ans += "0";
	(ans[0] == '1'&& s1[0] == s2[0] && s1[1] == s2[1] ) ? ans += "1" : ans += "0";
	(is_same_side(s1[2],s2[2]) && ans[1] == '1') ? ans += "1" : ans += "0";
	(ans[2] == '1' && abs(s1[2]-s2[2]) == 1) ? ans += "1" : ans += "0";
	std::cout<<ans<<std::endl;
	return 0;
		
	
} 
