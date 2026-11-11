#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool tongce(char a,char b){
	if(a=='A'||a=='B'||a=='C'){//a在左侧 
		if(b!=a&&b!='D'&&b!='F'){//b不在右侧 
			return true;
		}else return false;
	} else{//a右侧 
		if(b!=a&&b!='A'&&b!='B'&&b!='C'){
			return  true;
		}else return false;
	}
} 
bool ns(char a,char b){
	if(a=='A'){
		if(b=='B') return true;
		else return false; 
	}else if(a=='B'){
		if(b=='A'||b=='C') return true;
		else return false; 
	}else if(a=='C'){
		if(b=='B') return true;
		else return false; 
	}else if(a=='D'){
		if(b=='F') return true;
		else return false; 
	}else if(a=='F'){
		if(b=='D') return true;
		else return false; 
	}
}
int main() {
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1[0]==s3[0]&&s1[1]==s3[1]){//同一届车厢 
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){//tongyipai 
			cout<<1; 
			if(tongce(s2[2],s4[2])==true){//同侧 
				cout<<1;
				if(ns(s2[2],s4[2])==true){
					cout<<1<<endl;
				}else cout<<0<<endl;
			}else {
				cout<<"00";
			}
		}else{
			cout<<"000"<<endl;
		}
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	return 0;
}
