#include<bits/stdc++.h>
using namespace std;
string cabin1,lane1,cabin2,lane2;
bool ok1=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cabin1>>lane1>>cabin2>>lane2;
	if(cabin1==cabin2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(lane1[i]!=lane2[i]){
			ok1=false;
			cout<<"000";
			return 0;
		}
	}
	if(ok1) cout<<1;
	if((lane1[2]=='A'||lane1[2]=='B'||lane1[2]=='C')&&
	(lane2[2]=='A'||lane2[2]=='B'||lane2[2]=='C')||
	(lane1[2]=='D'||lane1[2]=='E')&&
	(lane2[2]=='D'||lane2[2]=='E')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	
	if(lane1[2]<='C'&&lane2[2]<='C'&&lane1[2]>='A'&&lane2[2]>='A'&&abs(lane1[2]-lane2[2])==1||
	lane1[2]<='E'&&lane2[2]<='E'&&lane1[2]>='D'&&lane2[2]>='D'&&abs(lane1[2]-lane2[2])==1) cout<<1;
	else cout<<0;
	return 0;
	//direct by XJ-J00035
}
