#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string c1,s1,c2,s2;
    string st;
    cin>>c1>>s1>>c2>>s2;
    bool f=0;
	if(c1==c2){
		st[0]='1';
		f=1;
	} 
	else{
		st[0]='0';
	}
	string cs,sc;
	bool flag=0;
	cs+=s1[0],cs+=s1[1];
	sc+=s2[0],sc+=s2[1];
	if(sc==cs&&f){
		st[1]='1'; 
		flag=1;
	}
	else{
		st[1]='0';
		st[3]='0';
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&flag&&f){
		st[2]='1';
	}
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&flag&&f){
		st[2]='1';
	}
	else{
		st[2]='0';
	}
	if(flag&&f){
		if((s1[2]==char(s2[2]+1)||s2[2]==char(s1[2]+1))){
			if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')){
				st[3]='0';
			}
			else{
				st[3]='1';
			}
		}
		else{
			st[3]='0';
		}
	}
	else{
		st[3]='0';
	}
	for(int i=0;i<4;i++){
		cout<<st[i];
	}
	return 0;
}
