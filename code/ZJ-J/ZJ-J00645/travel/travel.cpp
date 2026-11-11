#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(a==c){
		if(b[0]!=d[0]||b[1]!=d[1]){
			cout<<"1000";
			return 0;
		}
		if(b[2]=='A'&&(d[2]=='D'||d[2]=='F')){
			cout<<"1100";
			return 0;
		}
		if(b[2]=='B'&&(d[2]=='D'||d[2]=='F')){
			cout<<"1100";
			return 0;
		}
		if(b[2]=='C'&&(d[2]=='D'||d[2]=='F')){
			cout<<"1100";
			return 0;
		}
		if(b[2]=='D'&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
			cout<<"1100";
			return 0;
		}
		if(b[2]=='F'&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
			cout<<"1100";
			return 0;
		}
		if(b[2]=='A'&&d[2]=='B'){
			cout<<"1111";
			return 0;
		}
		if(b[2]=='B'&&(d[2]=='A'||d[2]=='C')){
			cout<<"1111";
			return 0;
		}
		if(b[2]=='C'&&d[2]=='B'){
			cout<<"1111";
			return 0;
		}
		if(b[2]=='D'&&d[2]=='F'){
			cout<<"1111";
			return 0;
		}
		if(b[2]=='F'&&d[2]=='D'){
			cout<<"1111";
			return 0;
		}
		cout<<"1110";
	}
	return 0;
}