#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x,rp,xp,isr=0,isx=0;
	string rc,xc;
	cin >> r >> rc >> x >> xc;
	if (r!=x) {
		cout << "0000";
		return 0;
	}
	rp=(rc[0]-'0')*10+(rc[1]-'0');
	xp=(xc[0]-'0')*10+(xc[1]-'0');
	if (xp!=rp){
		cout << "1000";
		return 0;
	}
	if (rc[2]=='A'||rc[2]=='B'||rc[2]=='C') isr=1;
	if (xc[2]=='A'||xc[2]=='B'||xc[2]=='C') isx=1;
	if (isx!=isr){
		cout << "1100";
		return 0;
	}
	if ((abs(rc[2]-xc[2])==1)&&!((((rc[2]=='C')&&(xc[2]=='D'))||((rc[2]=='D')&&(xc[2]=='C'))))){
		cout << "1111";
		return 0;
	}
	cout << "1110";
	return 0;
} 
