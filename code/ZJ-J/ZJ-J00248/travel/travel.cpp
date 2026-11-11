#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int f(string x){
	return (x[0]-'0')*10+(x[1]-'0');
}
bool j(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='A'))return 1;
	if((a=='B'&&b=='C')||(a=='C'&&b=='B'))return 1;
	if((a=='A'&&b=='C')||(a=='C'&&b=='A'))return 1;
	if((a=='F'&&b=='D')||(a=='D'&&b=='F'))return 1;
	return 0;
}
bool p(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='A'))return 1;
	if((a=='B'&&b=='C')||(a=='C'&&b=='B'))return 1;
	if((a=='F'&&b=='D')||(a=='D'&&b=='F'))return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int q1=f(c1),q2=f(s1),w1=f(c2),w2=f(s2);
	char q3=s1[2],w3=s2[2];
	if(q1==w1){
		cout<<1;
		if(q2==w2){
			cout<<1;
			if(j(q3,w3)){
				cout<<1;
				if(p(q3,w3)){
					cout<<1;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}