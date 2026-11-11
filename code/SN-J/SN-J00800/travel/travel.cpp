#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
		if(s1[1]==s2[1]&&s1[2]==s2[2]&&s1[1]>=0&&s2[1]<=9&&s1[1]<=9&&s2[1]>=0&&s1[2]>=0&&s2[2]<=9&&s1[2]<=9&&s2[2]>=0){
			cout<<"1";
			if((s1[2]=="C"&&s2[2]=="D")||(s1[2]=="D"&&s2[2]=="C")){
				cout<<"00";
			}
			else if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
				cout<<"11";
			}
		}
		else{
			cout<<"000";
		}
	return 0;
}
