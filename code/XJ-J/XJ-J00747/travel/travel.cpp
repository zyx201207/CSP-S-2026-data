#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cxr,zwr,cxx,zwx;
	cin >> cxr >> zwr >> cxx >>zwx;
	ll ans=0;
	if(cxr!=cxx){
		cout << "0000";
		return 0;
	}else ans+=1000;
	if(zwr[0]==zwx[0] && zwr[1]==zwx[1]){
		ans+=100;
	}else{
		cout << ans;
		return 0;
	}
	if(((zwr[2]=='A' || zwr[2]=='B' || zwr[2]=='C')&&(zwx[2]=='A' || zwx[2]=='B' || zwx[2]=='C')) || ((zwr[2]=='D' || zwr[2]=='F') && (zwx[2]=='D' || zwx[2]=='F'))){
		ans+=10;
	}else{
		cout << ans;
		return 0;
	}
	if((zwr[2]=='A' && zwx[2]=='B') || (zwr[2]=='B' && (zwx[2]=='A' || zwx[2]=='C')) || (zwr[2]=='C' && zwx[2]=='B') || (zwr[2]=='D' && zwx[2] =='F') || (zwx[2]=='A' && zwr[2]=='B') || (zwx[2]=='B' && (zwr[2]=='A' || zwr[2]=='C')) || (zwx[2]=='C' && zwr[2]=='B') || (zwx[2]=='D' && zwx[2]=='F')){
		ans+=1;
	}else{
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}