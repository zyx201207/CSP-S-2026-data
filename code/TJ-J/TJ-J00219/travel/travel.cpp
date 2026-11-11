#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool SameCar=false,SameRow=false,SamePart=false,NearBy=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)SameCar=true;
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&SameCar)SameRow=true;
	if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&SameRow){
		if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')SamePart=true;
	}if((a2[2]=='D'||a2[2]=='F')&&SameRow){
		if(b2[2]=='D'||b2[2]=='F')SamePart=true;
	}
	if(a2[2]=='A'&&SamePart)if(b2[2]=='B')NearBy=true;
	if(a2[2]=='B'&&SamePart)if(b2[2]=='A'||b2[2]=='C')NearBy=true;
	if(a2[2]=='C'&&SamePart)if(b2[2]=='B')NearBy==true;
	if((a2[2]=='D'||a2[2]=='F')&&SamePart)NearBy==true;
	if(SameCar)cout<<1;
	else cout<<"0";
	if(SameRow)cout<<"1";
	else cout<<"0";
	if(SamePart)cout<<"1";
	else cout<<"0";
	if(NearBy)cout<<"1";
	else cout<<"0";
	return 0;
} 
