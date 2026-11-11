#include<bits/stdc++.h>
using namespace std;
int cxr,cxx,zwr,zwx;
char l;
bool k=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cxr;
	for(int i=1;i<=2;i++){
		cin>>l;
		zwr=zwr*10+l-'0';
	}
	cin>>l;
	zwr=zwr*10+l-'A'+1;
	cin>>cxx;
	for(int i=1;i<=2;i++){
		cin>>l;
		zwx=zwx*10+l-'0';
	}
	cin>>l;
	zwx=zwx*10+l-'A'+1;
	if(cxr==cxx){cout<<1;}else {cout<<0;k=0;}
	if(k&&zwr/10==zwx/10)cout<<1;else {cout<<0;k=0;}
	if(k&&((zwr%10<=3&&zwx%10<=3)||(zwr%10>3&&zwx%10>3)))cout<<1;else {cout<<0;k=0;}
	if(k&&(zwr-zwx==1||zwx-zwr==1))cout<<1;else {cout<<0;k=0;}
	return 0;
}
