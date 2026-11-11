#include<bits/stdc++.h>
using namespace std;
#define ll long long
string cR,sR,cX,sX;
string ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cR>>sR>>cX>>sX;
	char a=sR[0],b=sR[1],c=sX[0],d=sX[1];
	char seatR=sR[2],seatX=sX[2];
	if(cR==cX) { //判断是否为同一车厢
		ans+='1';
		if(a==c&&b==d) { //判断是否为同一排
			ans+='1';
			if((seatR=='D'&&seatX=='F')||(seatR=='F'&&seatX=='D')
			        ||(seatR=='A'&&seatX=='C')||(seatR=='C'&&seatX=='A')
			        ||(seatR=='A'&&seatX=='B')||(seatR=='B'&&seatX=='A')
			        ||(seatR=='B'&&seatX=='C')||(seatR=='C'&&seatX=='B')) {  //判断是否为同一侧
				ans+='1';
				if((seatR=='A'&&seatX=='B')||(seatR=='B'&&seatX=='A')
				        ||(seatR=='B'&&seatX=='C')||(seatR=='C'&&seatX=='B')
				        ||(seatR=='D'&&seatX=='F')||(seatR=='F'&&seatX=='C')) { //判断是否相邻
					ans+='1';
				} else {
					ans+='0';
				}
			} else {
				ans+="00";
			}
		} else {
			ans="1000";
		}
	} else {
		ans="0000";
	}
	cout<<ans;
	return 0;
}
