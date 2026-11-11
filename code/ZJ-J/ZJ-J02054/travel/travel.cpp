#include<bits/stdc++.h>
using namespace std;

string ca,sa,cb,sb;
string la,lb;
	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	

	for(int i=0;i<=1;i++){
		la+=sa[i];
		lb+=sb[i];
	}
	if(la!=lb){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	
	if(sa[2]=='D' && sb[2]=='F') cout<<"11";
	else if(sb[2]=='D' && sa[2]=='F') cout<<"11";
	else if(sa[2]-sb[2]==1 && sa[2]!='D') cout<<"11";
	else if(sb[2]-sa[2]==1 && sb[2]!='D') cout<<"11";
	else if(sa[2]=='A' && sb[2]=='C') cout<<"10";
	else if(sb[2]=='A' && sa[2]=='C') cout<<"10";
	else cout<<"00";
	
	return 0;
}
