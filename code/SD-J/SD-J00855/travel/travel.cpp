#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int rc,xc;
	string rs,xs;
	cin>>rc>>rs>>xc>>xs;
	int rp,xp;
	rp = rs[0]-'0';
	rp = rp * 10 + rs[1]-'0';
	xp = xs[0]-'0';
	xp = xp * 10 + xs[1]-'0';
	char rz,xz;
	rz=rs[2];
	xz = xs[2];
	if(rc == xc){
		cout<<1;
		if(rp == xp){
			cout<<1;
			if((rz == 'C' && xz == 'D') || (rz == 'D' && xz == 'C')){
				cout<<"00";
			}else{
				cout<<1;
				if(abs(rz-xz)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	cout<<'\n';
	return 0;
}
