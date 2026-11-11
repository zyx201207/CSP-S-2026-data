#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string c1,s1,c2,s2,ans;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		ans = '1';
	}
	else{
		ans = '0';
	}
	if(s1[0]==s2[0]){
		if(s1[1]==s2[1]){
			ans+='1';
			if((s1[2]>='D')&&(s2[2]<='C')){
				ans+='0';
			}
			else if((s2[2]>='D')&&(s1[2]<='C')){
				ans+='0';
			}
			else{
				ans+='1';
				if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
					ans+='1';
				}
				else{
					ans+='0';
				}
			}
		}
		else{
			ans+='0';
		}
	}
	else{
		ans+='0';
	}
	cout << ans;
	return 0;
}