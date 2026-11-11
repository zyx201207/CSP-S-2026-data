//考号:SN-J00794 学校:西安翱翔中学 姓名:史夏澍  
#include<bits/stdc++.h>
using namespace std;
struct nod{
	string x,y;
}a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<=1;i++){
		cin>>a[i].x>>a[i].y;
	}
	if(a[0].x==a[1].x){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0].y[0]==a[1].y[0] && a[0].y[1]==a[1].y[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((a[0].y[2]=='A' || a[0].y[2]=='B') || a[0].y[2]=='C') && ((a[1].y[2]=='A' || a[1].y[2]=='B') || a[1].y[2]=='C')) cout<<"1";
	else if((a[0].y[2]=='D' || a[0].y[2]=='F') && (a[1].y[2]=='D' || a[1].y[2]=='F')) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if((a[0].y[2]=='A' && a[1].y[2]=='B') || (a[0].y[2]=='B' && a[1].y[2]=='A') || (a[0].y[2]=='B' && a[1].y[2]=='C') || (a[0].y[2]=='C' && a[1].y[2]=='B') || (a[0].y[2]=='D' && a[1].y[2]=='F') || (a[0].y[2]=='F' && a[1].y[2]=='D')) cout<<"1";
	else cout<<"0";
	return 0;
	
}
