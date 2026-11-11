#include<bits/stdc++.h>
using namespace std;
char c;
int x,xx,y,yy,t,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c;
	x+=int(c-'0')*10;
	cin>>c;
	x+=int(c-'0');
	cin>>c;
	xx+=int(c-'0')*10;
	cin>>c;
	xx+=int(c-'0');
	cin>>c;
	t+=int(c-'A'+1);
	cin>>c;
	y+=int(c-'0')*10;
	cin>>c;
	y+=int(c-'0');
	cin>>c;
	yy+=int(c-'0')*10;
	cin>>c;
	yy+=int(c-'0');
	cin>>c;
	tt+=int(c-'A'+1);
	if(t==6)t--;
	if(tt==6)tt--;
	if(x!=y){
		cout<<"0000";
		return 0;
	}
	if(xx!=yy){
		cout<<"1000";
		return 0;
	}
	if((t>=4&&tt<=3)||(t<=3&&tt>=4)){
		cout<<"1100";
		return 0;
	}
	if(abs(t-tt)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}

