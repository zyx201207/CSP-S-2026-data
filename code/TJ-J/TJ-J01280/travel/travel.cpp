#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char C=C,B=B,A=A;
	if(a!=c){
		cout<<"0000";
		return 0;
	}else{
		if(b[0]==d[0]&&b[1]==d[1]){
			if(b[2]==d[2]+1&&b[2]!='C'){
				cout<<"1111";
			}else if(d[2]==b[2]+1&&d[2]!='C'){
				cout<<"1111";
			}else{
				if(b[2]==A&&d[2]!=B){
					cout<<"1100";
				}else if(b[2]==B&&d[2]!=A){
					cout<<"1100";
				}else{
					cout<<"1110";
				}
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}
	
	
	
	
	return 0;
}
