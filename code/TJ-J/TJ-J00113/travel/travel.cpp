#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  rchi,xchi;
	char rzuo,xzuo;
	cin>>rchi>>rzuo>>xchi>>xzuo;
	if(rchi==xchi){
		cout<<"1";
		int rqian=rzuo/1000;
		int rbai=rzuo/100%10;
		int xqian=xzuo/1000;
		int xbai=xzuo/100%10;
		if(rqian*10+rbai==xqian*10+xbai){
			cout<<"1";
		}
		int rzuo1=rzuo;
		int xzuo1=xzuo;
		int rshi=rzuo1/10%10;
		int rge=rzuo1%10;
		int xshi=xzuo1/10%10;
		int xge=xzuo1%10;
		if(rshi*10+rge=='A'){
			rzuo1=1;
		}else if(rshi*10+rge=='B'){
			rzuo1=2;
		}else if(rshi*10+rge=='C'){
			rzuo1=3;
		}else if(rshi*10+rge=='D'){
			rzuo1=4;
		}else if(rshi*10+rge=='F'){
			rzuo1=5;
		}else if(xshi*10+xge=='A'){
			xzuo1=2;
		}else if(xshi*10+xge=='B'){
			xzuo1=2;
		}else if(xshi*10+xge=='C'){
			xzuo1=3;
		}else if(xshi*10+xge=='D'){
			xzuo1=4;
		}else if(xshi*10+xge=='F'){
			xzuo1=5;
		}
		if(rzuo1<=3&&xzuo1<=3){
			cout<<"1";
		}if(rzuo1>=4&&xzuo1>=4){
			cout<<"1";
		}
		
		
		if(rzuo1==1&&xzuo1==2){
			cout<<"1";
		}else if(rzuo1==2&&xzuo1==1){
			cout<<"1";
		}else if(rzuo1==2&&xzuo1==3){
			cout<<"1";
		}else if(rzuo1==3&&xzuo1==2){
			cout<<"1";
		}else if(rzuo1==4&&xzuo1==5){
			cout<<"1";
		}else if(rzuo1==5&&xzuo1==4){
			cout<<"1";
		}
	}cout<<"0";
	return 0;
}
