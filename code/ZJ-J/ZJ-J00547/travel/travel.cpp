#include<bits\stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
				if(s1[2]=='B'||s2[2]=='B'){
					ans="1111";
				}else{
					ans="1110";
				}
			}else if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'){
				ans="1111";
			}else{
				ans="1100";
			}
		}else{
			ans="1000";
		}
	}else{
		ans="0000";
	}
	cout<<ans<<endl;
	return 0;
} 
