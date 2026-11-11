#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cjj_c1,cjj_s1,cjj_c2,cjj_s2;
	cin>>cjj_c1>>cjj_s1>>cjj_c2>>cjj_s2;
	if(cjj_c1!=cjj_c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(cjj_s1[0]!=cjj_s2[0]||cjj_s1[1]!=cjj_s2[1]){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	int cjj_1=cjj_s1[2],cjj_2=cjj_s2[2];
	if((cjj_1<='C'&&cjj_2>='D')||(cjj_2<='C'&&cjj_1>='D')){
		cout<<"00";
		return 0; 
	}
	else cout<<"1";
	if(abs(cjj_1-cjj_2)>1){
		cout<<"0";
		return 0;
	}
	else cout<<"1";
	return 0;
} 
