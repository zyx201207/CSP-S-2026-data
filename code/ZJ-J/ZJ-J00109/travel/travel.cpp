#include<bits/stdc++.h>
using namespace std;
string s,t,ss,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>t>>ss>>tt;
	if(s==ss)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	string l_1=t.substr(0,2);
	string l_2=tt.substr(0,2);
	if(l_1==l_2)cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	char c_1=t[2];
	char c_2=tt[2];
	bool f=0;
	for(char c='A';c<='C';c++){
		for(char d='A';d<='C';d++){
			if(c==c_1&&d==c_2){
				cout<<'1';
				f=1;
				break;
			}
		}
		if(f==1)break;
	}
	if(f==0){
		if((c_1=='D'&&c_2=='F')||(c_1=='F'&&c_2=='D'))cout<<"11";
		else cout<<"00";
		return 0;
	}
	if(c_1>c_2)swap(c_1,c_2);
	if((c_1=='A'&&c_2=='B')||(c_1=='B'&&c_2=='C'))cout<<'1';
	else cout<<'0';
	return 0;
}