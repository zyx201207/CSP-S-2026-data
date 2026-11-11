#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	cin>>a>>b>>a1>>b1;
	if (a==a1){
		cout<<1;
	}else {
	    cout<<"0000";
	    return 0;
	}
	int bbb;
	for (int i=0;i<2;i++){
		if (b[i]==b1[i]) bbb++;
	}
	if (bbb==2) cout<<1;
	else {
		
		
	    cout<<"000";
	    return 0;
		}
	char Q1=b[2];
	char Q2=b1[2];
	if ((Q1=='A' || Q1=='B' || Q1=='C')){
		if (Q2=='A' || Q2=='B' || Q2=='C') cout<<1;
		else {cout<<"00"; return 0;}
	}else{
		if (Q2=='D' || Q2=='F') cout<<1;
		else {cout<<"00"; return 0;}
	}
	if (Q1=='A' && Q2=='B' || Q1=='B' && Q2=='C' || Q1=='B' && Q2=='A' || Q1=='C' && Q2=='B' || Q1=='D' && Q2=='F' || Q1=='F' && Q2=='D') cout<<1;
	else cout<<0;
	return 0;
}
