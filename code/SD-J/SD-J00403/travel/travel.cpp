#include<bits/stdc++.h>
using namespace std;
int s(char c){
	if(c=='A'||c=='B'||c=='C')
		return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){
		cout<<"0000";
		return 0;
	}
	int r1=(sr[0]-'0')*10+sr[1]-'0';
	int x1=(sx[0]-'0')*10+sx[1]-'0';
	char r2=sr[2],x2=sx[2];
	if(r1!=x1){
		cout<<"1000";
		return 0;
	}
	if(s(r2)!=s(x2)){
		cout<<"1100";
		return 0;
	}
	if((r2=='A'&&x2=='C')||(r2=='C'&&x2=='A')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
