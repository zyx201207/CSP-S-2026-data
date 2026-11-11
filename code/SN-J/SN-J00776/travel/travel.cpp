//姓名:张泽凯,考号:SN-J00776,学校:西安交通大学附属中学 
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	bool tc=0;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)cout<<1;
	else cout<<0;
	if(ca==cb&&sa[1]==sb[1]){
		cout<<1;
		tc=1;
	}
	else cout<<0;
	if(tc==1){
		if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C'){
			if(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')cout<<1;
			else cout<<0;
		}else{
			if(sb[2]=='D'||sb[2]=='F')cout<<1;
			else cout<<0;
		}
	}else{
		cout<<0;
	}
	if((sa[2]=='A'&&sb[2]=='B')||(sa[2]=='B'&&sb[2]=='A')||(sa[2]=='C'&&sb[2]=='B')||(sa[2]=='B'&&sb[2]=='C')||(sa[2]=='F'&&sb[2]=='D')||(sa[2]=='D'&&sb[2]=='F')){
		if(tc==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
