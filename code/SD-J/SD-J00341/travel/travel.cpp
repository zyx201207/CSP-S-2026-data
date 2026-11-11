#include<bits/stdc++.h>
#define int long long
using namespace std;
int kkk(char x,char y){
	int xz,yz;
	if(x=='F'||x=='D')xz=1;
	else xz=2;
	if(y=='F'||y=='D')yz=1;
	else yz=2;
	if(xz==yz){
		if(xz==1||x-y==1||x-y==-1){
			return 2;
		}else return 1;
	}else return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string cr,sr,cx,sx;
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx)cout<<"1";
    else{
    	cout<<"0000";
    	return 0;
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char x=sr[2],y=sx[2];
	if(kkk(x,y)==2)cout<<"11";
	else if(kkk(x,y)==1)cout<<"10";
	else cout<<"00";
	return 0;
}

