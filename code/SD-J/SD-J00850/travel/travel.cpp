#include<cstdio>
#include<iostream>
using namespace std;
string ax,ay,bx,by;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>ay>>bx>>by;
	if(ax==bx){
		cout<<"1";
		if(ay[0]==by[0]&&ay[1]==by[1]){
			cout<<"1";
			if(ay[2]>='D'&&by[2]>='D'||ay[2]<'D'&&by[2]<'D'){
				cout<<"1";
				if(ay[2]>='D'&&by[2]>='D'||(ay[2]<'D'&&by[2]<'D'&&(ay[2]-by[2]==1||by[2]-ay[2]==1))){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
