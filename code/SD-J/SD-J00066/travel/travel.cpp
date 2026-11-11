#include<bits/stdc++.h>
using namespace std;
int change(string s){
	if(s[0]=='0'){
		return s[1]-'0';
	}
	else{
		return 10+s[1]-'0';
	}
}
int pai(string s){
	return change(s);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx,sx,cy,sy;
	cin>>cx>>sx>>cy>>sy;
	if(change(cx)==change(cy)){
		cout<<1;
		if(pai(sx)==pai(sy)){
			cout<<1;
			if(((sx[2]=='A'||sx[2]=='B'||sx[2]=='C')&&(sy[2]=='A'||sy[2]=='B'||sy[2]=='C'))||((sx[2]=='D'||sx[2]=='F')&&(sy[2]=='D'||sy[2]=='F'))){
				cout<<1;
				if((sx[2]=='A'&&sy[2]=='B')||(sx[2]=='B'&&sy[2]=='A')||(sx[2]=='B'&&sy[2]=='C')||(sx[2]=='C'&&sy[2]=='B')||(sx[2]=='D'&&sy[2]=='F')||(sx[2]=='F'&&sy[2]=='D')){
					cout<<1<<endl;
				}
				else{
					cout<<0<<endl;
				}
			}
			else{
				cout<<0<<0<<endl;
			}
		}
		else{
			cout<<0<<0<<0<<endl;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	return 0;
}
