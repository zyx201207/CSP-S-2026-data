#include<bits/stdc++.h>
#define int long long
using namespace std;
string ca,sa,cc,sc;
int ansa,ansb,ansc,ansd;
bool tc(char a,char b){
	if(a<='C'&&b<='C'){
		return true;
	}
	if(a>='D'&&b>='D'){
		return true;
	}
	return false;
}
bool xl(char a,char b){
	if(a<='C'&&b<='C'&&(abs(a-b)==1)){
		return true;
	}
	if(a>='D'&&b>='D'&&(abs(a-b)==2)){
		return true;
	}
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ca>>sa>>cc>>sc;
	int ccxa=(ca[0]-'0')*10+(ca[1]-'0'),ccxc=(cc[0]-'0')*10+(cc[1]-'0');
	int ppa=(sa[0]-'0')*10+(sa[1]-'0'),ppc=(sc[0]-'0')*10+(sc[1]-'0');
	char za=sa[2],zc=sc[2];
	if(ccxa==ccxc){
		ansa=1;
	}
	if(ccxa==ccxc&&ppa==ppc){
		ansb=1;
	}
	if(ccxa==ccxc&&ppa==ppc&&tc(za,zc)){
		ansc=1;
	}
	if(ccxa==ccxc&&ppa==ppc&&tc(za,zc)&&xl(za,zc)){
		ansd=1;
	}
	cout<<ansa<<ansb<<ansc<<ansd;
	return 0;
}
