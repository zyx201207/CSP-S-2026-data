//liushaoang SN-J00738 FuLun
#include<bits/stdc++.h>
#define st string
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	st c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=false;
	bool flag_car=false;
	bool flag_xiangling=false;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		flag_car=true;
		flag=true;
		flag_xiangling=true;
	}
	if(flag_car=false and s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
		flag=true;
		flag_xiangling=true;
	}
	
	char c=s1[2];
	char c_1=s2[2];
	if(flag=false  and c>='A' && c<='C' and c_1>='A' && c_1<='C' || c>='D' && c<='F' and  c_1>='D' && c_1<='C'){
		cout<<1;
	}
	else{
		cout<<0;
		flag_xiangling=true;
	}
	if(flag_xiangling = false && c=='A' and c_1=='B'){
		cout<<1;
	}
	else if(flag_xiangling = false && c=='B' and c_1=='C'){
		cout<<1;
	}
	else if(flag_xiangling = false && c=='D' and c_1=='F'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
 
