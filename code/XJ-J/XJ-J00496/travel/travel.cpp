#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sf,ss,a1,b1;
	char cf[3],cs[3],a2,b2;
    int aa=0,bb=0;
	int ans=0,cum=0,k=0,u=0;
	cin>>sf>>cf>>ss>>cs;
	if(sf==ss){
		ans=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(cf[0]!='0')
	    aa=(cf[1]-'0');
	else
	    aa=10+(cf[1]-'0');
	bb=(cs[0]-'0')*10+(cs[1]-'0');
	a2=cf[2],b2=cs[2];
	if(aa==bb){
	    cum=1;
	}else{
		cout<<ans<<"000";
		return 0;
	}
	if((a2<='C'&&b2<='C')||(a2>='D'&&b2>='D')) {
		k=1;
	}else{
		cout<<ans<<cum<<"00";
	}
	if((a2=='A'&&b2=='B')||(a2=='B'&&(b2=='A'||b2=='C'))||(a2=='C'&&b2=='B')||(a2=='D'&&b2=='F')||(a2=='F'&&b2=='D')){
        u=1;
	}else{
		cout<<ans<<cum<<k<<"0";
		return 0;
	}
	cout<<ans<<cum<<k<<u;
	return 0;
}