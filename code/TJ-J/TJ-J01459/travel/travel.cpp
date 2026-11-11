#include<bits/stdc++.h>
using namespace std;
#define int long long
string cc1,ss1,cc2,ss2;
int aa1,aa2,pp1,pp2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1==cc2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(ss1[1]!=ss2[1]){
		cout<<"000";
		return 0;}
	else if(ss1[0]!=ss2[0]){
		cout<<"000";
		return 0;
	}
	else{cout<<1;}
		
		
		
	if(ss1[2]=='A'||ss1[2]=='B'||ss1[2]=='C') aa1=1;
	else aa1=2;
	if(ss2[2]=='A'||ss2[2]=='B'||ss2[2]=='C') aa2=1;
	else aa2=2;
	
	if(aa1==aa2) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(ss1[2]=='A') pp1=1;
	if(ss1[2]=='B') pp1=2;
	if(ss1[2]=='C') pp1=3;
	if(ss1[2]=='D') pp1=5;
	if(ss1[2]=='F') pp1=6;
	if(ss2[2]=='A') pp2=1;
	if(ss2[2]=='B') pp2=2;
	if(ss2[2]=='C') pp2=3;
	if(ss2[2]=='D') pp2=5;
	if(ss2[2]=='F') pp2=6;
	if(abs(pp1-pp2)==1) cout<<1;
	else cout<<0;
	return 0;
}
