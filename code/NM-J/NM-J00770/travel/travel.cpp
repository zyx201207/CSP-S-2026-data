#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	cin>>a>>b>>c>>d;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(a==c){
		if(b[1]==d[1]&&b[0]==d[0]){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'  &&  d[2]=='A'||d[2]=='B'||d[2]=='C'  ||   b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F'){
				if(abs((b[2]+b[1])-(d[2]+d[1]))==1  ||  b[2]=='D'&&d[2]=='F'  ||  b[2]=='F'&&d[2]=='D'){
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
