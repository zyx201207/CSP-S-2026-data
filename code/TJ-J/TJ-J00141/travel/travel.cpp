#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;bool flag=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0]!=c2[0] || c1[1]!=c2[1]){
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	else{
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				flag=1;
			}
		}
		if(flag==1){
			cout << 1000;
			return 0;
		} 
		else {
		
			if(s1[2]-'0'+1==s2[2]-'0' || s1[2]-'0'-1==s2[2]-'0'){
				if((s1[2]=='C'&&s2[2]=='D') || (s1[2]=='D'&&s2[2]=='C')){
					cout << 1100;
					return 0;
				}
				else{
					cout << 1111;
					return 0;
				}
			}
	        else{
				if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
					cout << 1110;
					return 0;
				}
				else{
					cout << 1100;
				}
			} 
		}
	}
	return 0;
}
