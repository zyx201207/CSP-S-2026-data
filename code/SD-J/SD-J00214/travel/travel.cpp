#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool h(char a,char b){
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='B'&&b=='A') return 1;
	if(a=='C'&&b=='B') return 1;
	if(a=='D'&&b=='F') return 1;
	if(a=='F'&&b=='D') return 1;
	return 0;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	char id1=s1[2],id2=s2[2];
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((id1>='A'&&id1<='C'&&id2>='A'&&id2<='C')||(id1>='D'&&id1<='F'&&id2>='D'&&id2<='F'))){
		cout<<1;
		if(h(id1,id2)){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	
	return 0;
}
