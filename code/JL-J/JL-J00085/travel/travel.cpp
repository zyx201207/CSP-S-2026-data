#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int ss1=(s1[0]-'0')*10+(s1[1]-'0');
	int ss2=(s2[0]-'0')*10+(s2[1]-'0');
	char tt=s1[2],cc=s2[2];
	if(c1==c2) cout<<1;
	else{
		cout<<0000;
		return 0;
	}
	if(ss1==ss2) cout<<1;
	else{
		cout<<000;
		return 0;
	}
	if(tt=='A'||tt=='B'||tt=='C'){
		if(cc=='A'||cc=='B'||cc=='C'){
			cout<<1;
			if((tt=='A'&&cc=='B')||(tt=='B'&&cc=='A')||(tt=='B'&&cc=='C')||(tt=='C'&&cc=='B')){
				cout<<1;
			}
			else cout<<0;
		}
		else{
			cout<<00;
			return 0;
		}
	}
	else if(tt=='D'||tt=='F'){
		if(cc=='D'||cc=='F'){
			cout<<1;
			if((tt=='D'&&cc=='F')||(tt=='F'&&cc=='D')){
				cout<<1;
			}
			else cout<<0;
		}
		else{
			cout<<00;
			return 0;
		}
	}
	return 0;
}
