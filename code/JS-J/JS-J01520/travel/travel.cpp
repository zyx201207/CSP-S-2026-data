#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			bool e,f;
			if(b[2]<='C')e=0;
			else e=1;
			if(d[2]<='C')f=0;
			else f=1;
			if(e==f){
				cout<<"1";
				if(e==0){
					if(b[2]==d[2]+1||d[2]==b[2]+1){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"1";
				}
			}
			else{
				cout<<"00";
			}
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
