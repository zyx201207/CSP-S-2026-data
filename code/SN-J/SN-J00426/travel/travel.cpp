#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1(char a,char b){
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&(b=='A'||b=='C')) return 1;
	if(a=='C'&&b=='B') return 1;
	if((a=='F'&&b=='D')||(a=='D'&&b=='F')) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int n=(s1[0]-'0')*10+(s1[1]-'0');
		int m=(s2[0]-'0')*10+(s2[1]-'0');
		if(n==m){
			cout<<1;
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s1[2]=='D'||s1[2]=='F'))){
				cout<<1;
				if(f1(s1[2],s2[2])){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		} 
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
