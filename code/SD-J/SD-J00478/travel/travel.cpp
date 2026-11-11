#include<bits/stdc++.h>
using namespace std;

int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string ax,az,bx,bz;
	cin>>ax>>az>>bx>>bz;
	if(ax==bx){
		cout<<"1";
		if(az[0]==bz[0]&&az[1]==bz[1]){
			cout<<"1";
			if((az[2]=='A'||az[2]=='B'||az[2]=='C')&&(bz[2]=='A'||bz[2]=='B'||bz[2]=='C')&&az[2]!=bz[2]){
				cout<<"1";
				if(az[2]=='B'||bz[2]=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((az[2]=='D'||az[2]=='F')&&(bz[2]=='D'||bz[2]=='F')&&az[2]!=bz[2]){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;//delete my freopen and all debug words; 
}

