#include<bits/stdc++.h>
using namespace std;
int ge(char c){
	if(c=='F'||c=='D')return 1;
	return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(ge(b[2])==ge(d[2])){
				cout<<"1";
				if(ge(b[2])==1)cout<<"1";
				else{
					if(abs((int)b[2]-d[2])==1)cout<<"1";
					else cout<<"0";
				}
			}
			else cout<<"00";
		}
		else {
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
