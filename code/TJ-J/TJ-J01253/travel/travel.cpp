#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		ans+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";
			char t1 = s1[2];
			char t2 = s2[2];
			if(t1>='A'&&t2>='A'&&t1<='C'&&t2<='C'||t1=='D'&&t2=='F'||t1=='F'&&t2=='D'){
				ans+="1";
				if(t1=='D'&&t2=='F'||t1=='F'&&t2=='D'||(t1-t2)>=-1&&(t1-t2)<=1){
					ans+="1";
				}else ans+="0";
			}else ans+="00";
		}
		else ans+="000";
	}
	else{
		ans+="0000";
	}
	cout << ans << "\n";
	return 0; 
} 
//02 01A 02 01B
