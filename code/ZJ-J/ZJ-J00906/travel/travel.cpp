#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<endl;
	}else{
		string bb,dd;
		bb="",dd="";
		bb=b[0]+b[1];
		dd=d[0]+d[1];
		if(bb!=dd){
			cout<<"1000";
		}else{
			if((b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='C'&&d[2]=='A')||(b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D')){
				if(!((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}
	}
	return 0;
}
