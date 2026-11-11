#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string ans = "";
	if(c1[0] == c2[0] && c1[1] == c2[1]) ans+='1';
	else ans+='0';
	if(s1[0] == s2[0] && s1[1] == s2[1] && ans[0] == '1') ans+='1';
	else ans+='0';
	if(((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) && ans[1] == '1'){
		ans+='1';
	}else ans+='0';
	if(abs(s1[2] - s2[2]) == 1 && ans[2] == '1') ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
