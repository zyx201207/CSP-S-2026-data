#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=int(c1[0]-'0')*10+int(c1[1]-'0'),y=int(c2[0]-'0')*10+int(c2[1]-'0');
	if(x==y){
		cout<<1;
		x=int(s1[0]-'0')*10+int(s1[1]-'0');
		y=int(s2[0]-'0')*10+int(s2[1]-'0');
		if(x==y){
			cout<<1;
			char s=s1[2],t=s2[2];
			if(s>t) swap(s,t);
			if(s>='D'){
				cout<<"11";
			}
			else if(t<='C'){
				cout<<1;
				if(t=='B'&&s=='A') cout<<1;
				else if(t=='C'&&s=='B') cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
