#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			int a1,a2;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				a1=1;
			}else{
				a1=2;
			}
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				a2=1;
			}else{
				a2=2;
			}
			if(a1==a2){
				if(abs(d[2]-b[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
