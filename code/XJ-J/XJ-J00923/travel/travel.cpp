#include<bits/stdc++.h>
using namespace std;
int c(string s){//string to int 
	if(s[0]=='0') return s[1]-'0';
	else{
		return 10*(s[0]-'0')+s[1]-'0';
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sc1,ss1,sc2,ss2;
	cin>>sc1>>ss1>>sc2>>ss2;
	if(c(sc1)==c(sc2)){//the check 1
		cout<<"1";
		
		string p="  ";
		p[0]=ss1[0];//the check 2
		p[1]=ss1[1];
		int a=c(p);
		string q="  ";
		q[0]=ss2[0];
		q[1]=ss2[1];
		int b=c(q);
		if(a==b){
			cout<<"1";
			
			char c=ss1[2];//the check 3
			char d=ss2[2];
			if((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C')){//ÅÐ¶Ï c=A|b|cÇÒd==A|B|C 
				cout<<"1";
				//ÅÐ¶ÏÏàÁÚ the check 4
				if(c=='A'){
					if(d=='B')cout<<"1";
					else cout<<"0";
				}else if(c=='B'){
					cout<<"1";
				}else if(c=='C'){
					if(d=='B')cout<<"1";
					else cout<<"0";
				}
				
			}else if((c=='D'||c=='F')&&(d=='D'||d=='F')){//ÅÐ¶Ïc=D|FÇÒd=D|F 
				cout<<"11";
			}else cout<<"00";
			
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
} 
