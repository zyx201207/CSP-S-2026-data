#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1 == c2){
		ans+="1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			ans+="1";
			if(s1[2] == 'A' && s2[2] == 'B'){
				ans+="11";
			}else if(s1[2] == 'A' && s2[2] == 'C'){
				ans+="10";
			}else if(s1[2] == 'B' && s2[2] == 'A'){
				ans+="11";
			}else if(s1[2] == 'B' && s2[2] == 'C'){
				ans+="11";
			}else if(s1[2] == 'C' && s2[2] == 'A'){
				ans+="10";
			}else if(s1[2] == 'C' && s2[2] == 'B'){
				ans+="11";
			}else if(s1[2] == 'D' && s2[2] == 'F'){
				ans+="11";
			}else if(s1[2] == 'F' && s2[2] == 'D'){
				ans+="11";
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans<<endl;
	return 0;
}
