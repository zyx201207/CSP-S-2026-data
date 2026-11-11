#include<bits/stdc++.h>
using namespace std;
int x,y;
string x1,y1;
int xp,yp;
char xe,ye;
bool check3(char de,char fe){
	if(de>fe)swap(de,fe);
	if(de<='C'&&fe>='D')return true;
	return false;
}
bool check4(char de,char fe){
	if(de>fe)swap(de,fe);
	if(de+1==fe)return false;
	if(de=='D'&&fe=='F')return false;
	return true;
}
int main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>x1>>y>>y1;
	xp=stoi(x1.substr(0,2));
	yp=stoi(y1.substr(0,2));
	xe=x1[2];ye=y1[2];
	if(x!=y){
		cout<<"0000"<<endl;
	}else if(xp!=yp){
		cout<<"1000"<<endl;
	}else if(check3(xe,ye)){
		cout<<"1100"<<endl;
	}else if(check4(xe,ye)){
		cout<<"1110"<<endl;
	}else{
		cout<<"1111"<<endl;
	}
	return 0;
}

