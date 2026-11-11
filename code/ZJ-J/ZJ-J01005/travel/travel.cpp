#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string ss1=s1.substr(0,2),ss2=s2.substr(0,2);
		if(ss1==ss2){
			cout<<"1";
			char cc1=s1[2],cc2=s2[2];
			if((cc1=='A'&&cc2=='B')||(cc1=='B'&&cc2=='A')||(cc1=='A'&&cc2=='C')||(cc1=='C'&&cc2=='A')||(cc1=='B'&&cc2=='C')||(cc1=='C'&&cc2=='B')||(cc1=='D'&&cc2=='F')||(cc1=='F'&&cc2=='D')){
			    cout<<"1";
			    if((cc1=='A'&&cc2=='B')||(cc1=='B'&&cc2=='A')||(cc1=='B'&&cc2=='C')||(cc1=='C'&&cc2=='B')||(cc1=='D'&&cc2=='F')||(cc1=='F'&&cc2=='D'))cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
