#include<bits/stdc++.h>
using namespace std;
string ar,br,as,bs;
int ha,hb,nua,nub;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>ar>>as>>br>>bs;
	if(ar==br){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	
	if((as[0]==bs[0])&&(as[1]==bs[1])){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	
	if(as[2]=='F'){
		ha=1;
	}else if(as[2]=='D'){
		ha=1;
	}else{
		ha=0;
	}
	
	if(bs[2]=='F'){
		hb=1;
	}else if(bs[2]=='D'){
		hb=1;
	}else{
		hb=0;
	}
	
	if(hb==ha){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	
	if(ha==1){
		cout<<'1';
	}else{
		nua=as[2]-'A';
		nub=bs[2]-'A';
		if(abs(nua-nub)==1){
			cout<<'1';
		}
		else{
			cout<<'0';
		}
	}
	return 0;
}
