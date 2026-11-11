//姓名：张邦寒  准考证号：SN-J00827 学校：西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c11,s11,c22,s22;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>s11>>c22>>s22;
	if(c11==c22){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string s111=s11.substr(0,2),s222=s22.substr(0,2);
	if(s111==s222) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char tl=s11[2],tlt=s22[2];
	if(tl=='A'||tl=='B'||tl=='C'){
		if(tlt=='A'||tlt=='B'||tlt=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(tlt=='D'||tlt=='F'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(tl=='A'||tl=='B'||tl=='C'){
		if(tl=='A'){
			if(tlt=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(tl=='B'){
			if(tlt=='A'||tlt=='C'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(tl=='C'){
			if(tlt=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else if(tl=='D'||tl=='F'){
		if(tl=='D'){
			if(tlt=='F'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(tl=='F'){
			if(tlt=='D'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}
