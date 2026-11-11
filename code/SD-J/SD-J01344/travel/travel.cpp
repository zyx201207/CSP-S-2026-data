#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x1,x2;
	string y1,y2;
	cin>>x1;
	cin>>y1;
	cin>>x2;
	cin>>y2;
	if(x1==x2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(x1==x2&&y1[0]+y1[1]==y2[0]+y2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if((x1==x2)&&(y1[0]+y1[1]==y2[0]+y2[1])&&((y1[2]=='A'&&(y2[2]=='B'||y2[2]=='C'))||(y1[2]=='B'&&(y2[2]=='A'||y2[2]=='C'))||(y1[2]=='C'&&(y2[2]=='A'||y2[2]=='B'))||(y1[2]=='D'&&(y2[2]=='F'))||(y1[2]=='F'&&(y2[2]=='D')))){
		cout<<1;
	}else{
		cout<<0;
	}
	if((x1==x2)&&((y1[0]+y1[1]==y2[0]+y2[1])&&((y1[2]=='A'&&(y2[2]=='B'||y2[2]=='C'))||(y1[2]=='B'&&(y2[2]=='A'||y2[2]=='C'))||(y1[2]=='C'&&(y2[2]=='A'||y2[2]=='B'))||(y1[2]=='D'&&(y2[2]=='F'))||(y1[2]=='F'&&(y2[2]=='D'))))&&(abs(y1[2]-y2[2])==1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
