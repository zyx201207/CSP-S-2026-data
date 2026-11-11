#include<bits/stdc++.h>
using namespace std;
bool b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,x3,x4,y1,y2,y3,y4;
	cin>>x1>>x2>>y1>>y2;
	x3=x4=x2;
	y3=y4=y2;
	if(x1==y1)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<x2.size()-1;i++){
		if(x2[i]!=y2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(x2[2]<='C')b1=1;
	else b1=0;
	if(y2[2]<='C')b2=1;
	else b2=0;
	if(b1==b2)cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(x2[2]=='A'&&y2[2]=='B')cout<<1;
	else if(x2[2]=='B'&&y2[2]=='C')cout<<1;
	else if(x2[2]=='D'&&y2[2]=='E')cout<<1;
	else if(x2[2]=='B'&&y2[2]=='A')cout<<1;
	else if(x2[2]=='C'&&y2[2]=='B')cout<<1;
	else if(x2[2]=='E'&&y2[2]=='D')cout<<1;
	else cout<<0;
	return 0;
}
//Trick||Treat!
