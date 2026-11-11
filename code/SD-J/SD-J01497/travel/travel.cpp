#include<iostream>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		bool f=1;
		for(int i=0;i<2;i++){
			if(b[i]!=d[i]) f=0;
		}
		if(f==1){
			cout<<'1';
			if((b[2]-'A')<=2&&(d[2]-'A')<=2){
				cout<<'1';
				if((b[2]-d[2])==1||(b[2]-d[2])==-1) cout<<'1';
				else cout<<'0';
			}
			else if((b[2]-'A')>2&&(d[2]-'A')>2){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
