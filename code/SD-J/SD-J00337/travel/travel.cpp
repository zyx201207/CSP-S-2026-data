#include<bits/stdc++.h>
using namespace std;
string dx1,dx2;
string seat1,seat2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>dx1>>seat1>>dx2>>seat2;
	int cnt1,cnt2;
	if(seat1[2]=='A')cnt1=1;
	if(seat1[2]=='B')cnt1=2;
	if(seat1[2]=='C')cnt1=3;
	if(seat1[2]=='D')cnt1=4;
	if(seat1[2]=='F')cnt1=5;
	if(seat2[2]=='A')cnt2=1;
	if(seat2[2]=='B')cnt2=2;
	if(seat2[2]=='C')cnt2=3;
	if(seat2[2]=='D')cnt2=4;
	if(seat2[2]=='F')cnt2=5;
	if(dx1==dx2){
		cout<<"1";
		if(seat1[0]+seat1[1]==seat2[0]+seat2[1]){
			cout<<"1";
			if(cnt1<=3&&cnt2<=3){
				cout<<"1";
				if(cnt1+1==cnt2||cnt1-1==cnt2)cout<<"1";
				else cout<<"0";
				}	
				else cout<<"00";
				if(cnt1>=4&&cnt2>=4){
				cout<<"1";
				if(cnt1+1==cnt2||cnt1-1==cnt2)cout<<"1";
				else cout<<"0";
				}
			    }
	        else cout<<"000";}
	
	else{
		cout<<"0000";
	}
	return 0;
}
