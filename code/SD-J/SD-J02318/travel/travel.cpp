#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>s2>>t1>>t2;
	if(s1!=t1) cout<<"0000";
	else{
		if(s2[0]==t2[0]&&s2[1]==t2[1]){
			for (char i='A';i<='C';i++){
				for (char j='D';j<='F';j++){
					if(s2[2]==i&&t2[2]==j){
						cout<<"1100";
						return 0;
					}
				}
			}
			if(s2[2]=='D'&&t2[0]=='F') cout<<"1111";
			else{
				if(abs(s2[2]-t2[2])==1) cout<<"1111";
				else cout<<"1110";
			}
		}
		else cout<<"1000";
	}
	return 0;
}
