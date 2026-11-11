#include<bits/stdc++.h>
using namespace std;
string ca,cb,za,zb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>ca>>za>>cb>>zb;
	if(ca==cb){
		string ha=za.substr(0,2),hb=zb.substr(0,2);
		if(ha==hb){
			char wa=za[2],wb=zb[2];
			if(wa>='A'&&wa<='C'&&wb>='A'&&wb<='C'){
				if((wa=='A'&&wb=='C')||(wa=='C'&&wb=='A'))cout<<1110;
				else cout<<1111;
			}
			else if((wa=='D'||wa=='F')&&(wb=='D'||wb=='F'))cout<<1111;
			else cout<<1100;
		}
		else cout<<1000;
	}
	else cout<<"0000";
	return 0;
}