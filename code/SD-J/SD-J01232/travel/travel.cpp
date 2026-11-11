#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string cR,cX,sR,sX;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cR>>sR>>cX>>sX;
	if(cR==cX){
		cout<<'1';
		if(sR[0]==sX[0]&&sR[1]==sX[1]){
			cout<<'1';
			if(sR[2]>'C'&&sX[2]>'C'){
				cout<<"11";
				return 0;
			}else if(sR[2]<'D'&&sX[2]<'D'){
				cout<<'1';
				if(max(sR[2],sX[2])-min(sR[2],sX[2])==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
