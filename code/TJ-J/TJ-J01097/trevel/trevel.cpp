#include<bits/stdc++.h>
using namespace std;
bool is_beside(char a,char b){
	if(a=='A' && b=='B'){
		return 1;
	}else if(a=='B' && b=='C'){
		return 1;
	}else if(a=='D' && b=='F'){
		return 1;
	}else if(b=='A' && a=='B'){
		return 1;
	}else if(b=='B' && a=='C'){
		return 1;
	}else if(b=='D' && a=='F'){
		return 1;
	}else{
		return 0;
	}
}
bool is_line(char a,char b){
	if(a=='A' && b=='B'){
		return 1;
	}else if(a=='B' && b=='C'){
		return 1;
	}else if(a=='D' && b=='F'){
		return 1;
	}else if(a=='A' && b=='C'){
		return 1;
	}else if(b=='A' && a=='B'){
		return 1;
	}else if(b=='B' && a=='C'){
		return 1;
	}else if(b=='D' && a=='F'){
		return 1;
	}else if(b=='A' && a=='C'){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1] && s1[0]==s2[0]){
			cout<<1;
			if(is_line(s1[2],s2[2])){
				cout<<1;
				if(is_beside(s1[2],s2[2])){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<00;
				return 0;
			}
		}else{
			cout<<000;
			return 0;
		}
	}else{
		cout<<0000;
		return 0;
	}
}
