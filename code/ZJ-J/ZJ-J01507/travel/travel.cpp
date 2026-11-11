#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string S1,S2;int C1,C2;
	cin>>C1>>S1>>C2>>S2;
	if(C1!=C2){
		cout<<"0000";return 0;
	}cout<<1;
	int l1=(S1[0]-'0')*10+S1[1]-'0',l2=(S2[0]-'0')*10+S2[1]-'0';char m1=S1[2],m2=S2[2];
	if(l1!=l2){
		cout<<"000";return 0;
	}cout<<1;
	if((m1<='C' && m2<='C')||(m1>'C'&&m2>'C')) cout<<1;
	else{
		cout<<"00";return 0;
	}
	if(m1<='C'){
		if(m2-m1==1 || m2-m1==-1) cout<<1;
		else cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}

