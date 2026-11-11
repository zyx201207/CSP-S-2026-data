#include<bits/stdc++.h>
using namespace std;
int rc,xc,rb,xb;
char rxy,xxy;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rb>>rxy;
	cin>>xc>>xb>>xxy;
	if(rc==xc){
		cout<<1;
		if(rb==xb){
			cout<<1;
			if(max((int)rxy,(int)xxy)-min((int)rxy,(int)xxy)==1){
				if(rxy=='C'&&xxy=='D'||rxy=='D'&&xxy=='C') cout<<"00";
				else cout<<"11";
			}
			else{
				if(rxy=='A'&&xxy=='C'||rxy=='C'&&xxy=='A') cout<<"10";
				else cout<<"00";
			}
			
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
