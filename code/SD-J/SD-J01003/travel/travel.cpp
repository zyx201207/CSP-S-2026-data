#include<iostream>
using namespace std;
long long trax,tray;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>trax>>x>>tray>>y;
	if(trax!=tray){
		cout<<"0000";
	}else{
		int	hangx=(x[1]-'0')+(x[0]-'0')*10;
		int hangy=(y[1]-'0')+(y[0]-'0')*10;
		if(hangx!=hangy){
			cout<<"1000";
		}else{
			char xlie=x[2],ylie=y[2];
			if(xlie<ylie) swap(xlie,ylie);
			if(xlie>='D'&&ylie<='C'){
				cout<<"1100";
			}else{
				if(xlie-ylie!=1) cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}
