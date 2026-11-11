#include<bits/stdc++.h>
using namespace std;
string ax,ay,bx,by;
string sx="ABC",sy="DF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>ax>>ay>>bx>>by;
	if(ax==bx){
		cout<<"1";
		if(ay[0]==by[0]&&ay[1]==by[1]){
			cout<<"1";
			bool ta=false,tb=false;
			int kx,ky;
			for(int i=0;i<3;i++){
				if(ay[2]==sx[i])ta=true,kx=i;
				if(by[2]==sx[i])ta=true,ky=i;
			}
			for(int i=0;i<2;i++){
				if(ay[2]==sy[i])tb=true,kx=i;
				if(by[2]==sy[i])tb=true,ky=i;
			}
			if(ta&&tb)cout<<"00";
			else{
				cout<<"1";
				if(abs(kx-ky)==1)cout<<"1";
				else cout<<"0";
			}
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
