#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ans;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2){
		ans = {1000};
		if(s1(1) == s2(1) && s1(0) == s2(0)){
			ans = {1100};
		}
	}else{
		ans = {0000};
		if(s1(1) == s2(1) && s1(0) == s2(0)){
			ans = {0100};
		}
	}
	cout >>ans;
	
	return 0;
}
