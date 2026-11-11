#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string rc,rz,xc,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	for(int i=0;i<2;i++){
		if(rz[i]!=xz[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if((rz[2]<='C'&&xz[2]<='C')||(rz[2]>='D'&&xz[2]>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(rz[2]-xz[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
