#include<bits/stdc++.h>
using namespace std;
string sa,sb,sc,sd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>sa>>sb>>sc>>sd;
	if(sa==sc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	char ca=sb[0],cb=sb[1],cc=sd[0],cd=sd[1];
	if(ca==cc&&cb==cd){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char ce=sb[2],cf=sd[2];
	if(((ce=='A'||ce=='B'||ce=='C')&&(cf=='A'||cf=='B'||cf=='C'))||((ce=='D'||ce=='F')&&(cf=='D'||cf=='F'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(ce=='A'&&cf=='B'||ce=='B'&&cf=='C'||ce=='D'&&cf=='F'||ce=='B'&&cf=='A'||ce=='C'&&cf=='B'||ce=='F'&&cf=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
