#include<bits/stdc++.h>
using namespace std;
string sr,sx,bx,br;
bool tong=0;
int x,y;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>br>>sr>>bx>>sx;
	if(br[0]==bx[0]&&br[1]==bx[1]){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;}
	if(sr[0]==sx[0]&&sr[1]==sx[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;}
    if(sr[2]=='F'){
        x=sr[2]-66;
    }
    else x=sr[2]-65;
    if(sx[2]=='F'){
        y=sx[2]-66;
    }
    else{
        y=sx[2]-65;
    }
    if((x<3&&y<3)||(y>2&&x>2)){
        cout<<"1";
    }
    else{
		cout<<"00";
		return 0;}
    if((x==4&&y==5)||(x==5&&y==4)||(x==2&&y==x-1||y==x+1)||(x==1&&y==2)||(x==3&&y==2))cout<<"1";
    else cout<<"0";
	return 0;
}
