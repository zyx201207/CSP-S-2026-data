#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(a== b)return true;
	else if(a!= 'F'&&a!='D'&& b!='F'&&b!='D')return true;
	else if(a == 'F'&&a=='D'&&b=='F'&&b=='D')return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0] != c2[0] ||c1[1] != c2[1]){
		return cout<<"0000",0;	
	}
	if(s1[0] != s2[0] ||s1[1] != s2[1]){
		if(check (s1[2],s2[2])){
			if(s1[2]=='A'&&s2[2] == 'B'){
				return true;
			}
			if(s1[2] == 'B'&&s2[2]=='C'){
				return true;
			}
			if(s1[2] == 'C'&&s2[2] == 'D'){
				return true;
			}
			if(s1[2] == 'D'&&s2[2]=='E'){
				return true;
			}
			if(s1[2] == 'E'&&s2[2] == 'F'){
				return true;
			}
			cout<<"1110";
			
}



}
return 0;
}

