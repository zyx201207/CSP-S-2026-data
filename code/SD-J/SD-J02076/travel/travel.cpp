#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct tick{
	string box;
	char seat[4];
};
bool third=1;
tick R,X;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R.box>>R.seat>>X.box>>X.seat;
	//start
	R.box==X.box?cout<<1:cout<<0;//1
	if(R.seat[0]==X.seat[0]&&R.seat[1]==X.seat[1])//2
	cout<<1;else {cout<<0;third=0;}
	if(third){//3
		if((R.seat[2]=='A'||R.seat[2]=='B'||R.seat[2]=='C')&&(X.seat[2]=='A'||X.seat[2]=='B'||X.seat[2]=='C')||(R.seat[2]=='D'||R.seat[2]=='F')&&(X.seat[2]=='D'||X.seat[2]=='F')){
			cout<<1;
		}else cout<<0;
	}else cout<<0;
	
	//bool step1=0,step2=0;//4ican't
	//if(R.box==X.box){
	//	if(R.seat)...
	//}else cout<<0;
	cout<<0;
	return 0;
}
