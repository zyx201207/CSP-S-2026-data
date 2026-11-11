#include<bits/stdc++.h>
using namespace std;
long long c1,c2,s1,s2;
string s_1,s_2;
char k1,k2;
bool ce(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='A')){
		return 1;
	}
	if((a=='A'&&b=='C')||(a=='C'&&b=='A')){
		return 1;
	}
	if((a=='C'&&b=='B')||(a=='B'&&b=='C')){
		return 1;
	}
	if((a=='E'&&b=='F')||(a=='E'&&b=='F')){
		return 1;
	}
	return 0;
}
bool lin(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='A')){
		return 1;
	}
	if((a=='C'&&b=='B')||(a=='B'&&b=='C')){
		return 1;
	}
	if((a=='E'&&b=='F')||(a=='E'&&b=='F')){
		return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s_1>>c2>>s_2;
	s1+=(s_1[1]-'0');
	s2+=(s_2[1]-'0');
	if(s_1[0]!='0'){
		s1+=10;
	}
	if(s_2[0]!='0'){
		s2+=10;
	}
	k1=s_1[2],k2=s_2[2];
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(ce(k1,k2)){
				cout<<1;
				if(lin(k1,k2)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00"; 
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
