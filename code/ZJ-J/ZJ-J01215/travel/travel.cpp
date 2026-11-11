#include<bits/stdc++.h>

using namespace std;
string c1,c2;
string s1,s2;
bool check(string a,string b){
	if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(b[2]=='D'||b[2]=='F'){
			return 1;
		}else{
			return 0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(check(s1,s2)){
				if(abs(int(s1[2])-int(s2[2]))==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
