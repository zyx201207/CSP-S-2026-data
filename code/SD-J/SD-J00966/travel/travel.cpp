#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
ll C1,S1,C2,S2;
char op1,op2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	C1=(c1[0]-'0')*10+(c1[1]-'0');
	C2=(c2[0]-'0')*10+(c2[1]-'0');
	if(C1!=C2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		S1=(s1[0]-'0')*10+(s1[1]-'0');
		S2=(s2[0]-'0')*10+(s2[1]-'0');
		if(S1!=S2){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
			op1=s1[2];
			op2=s2[2];
			if(op1>op2) swap(op1,op2);
			if((op1=='D'&&op2=='F')||(op1=='F'&&op2=='D')){
				cout<<"11";
				return 0;
			}else if((op1=='A'&&op2=='B')||(op1=='B'&&op2=='C')){
				cout<<"11";
			}else if(op1=='A'&&op2=='C'){
				cout<<"10";
			}else {
				cout<<"00";
			}
		}
	}
	return 0;
}
