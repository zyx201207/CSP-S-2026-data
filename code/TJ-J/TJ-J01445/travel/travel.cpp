#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	char a3,b3;
	for(int j=1;j<=4;j++){
		string s;
		cin >>s;
		if(j==1){
			for(int i=0;i<int(s.size());i++){
				if(s[i]>='1'&&s[i]<='9'){
					a1+=s[i];
				}
			}
		}
		if(j==2){
			for(int i=0;i<int(s.size());i++){
				if(s[i]>='1'&&s[i]<='9'){
					a2+=s[i];
				}else if(s[i]>='A'&&s[i]<='Z'){
					a3=s[i];
				}
			}
		}
		if(j==3){
			for(int i=0;i<int(s.size());i++){
				if(s[i]>='1'&&s[i]<='9'){
					b1+=s[i];
				}
			}
		}
		if(j==4){
			for(int i=0;i<int(s.size());i++){
				if(s[i]>='1'&&s[i]<='9'){
					b2+=s[i];
				}else if(s[i]>='A'&&s[i]<='Z'){
					b3=s[i];
				}
			}
		}
	}
	if(a1==b1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2==b2){
		cout<<"1";
	}else {
		cout<<"000";
		return 0;
	}
	if((a3=='A'||a3=='B'||a3=='C')&&(b3=='A'||b3=='B'||b3=='C')){
		cout<<"1";
	}else if((a3=='D'||a3=='E')&&(b3=='D'||b3=='E')){
		cout<<"1";
	}else {
		cout<<"00";
		return 0;
	}
	if(abs(a3-b3)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
