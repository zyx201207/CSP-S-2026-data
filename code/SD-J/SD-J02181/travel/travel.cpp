#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char cs1,cs2;
	scanf("%d %d%c",&c1,&s1,&cs1);
	scanf("%d %d%c",&c2,&s2,&cs2);
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((cs1=='A'&&cs2=='B')||(cs1=='A'&&cs2=='C')||(cs1=='B'&&cs2=='A')||(cs1=='B'&&cs2=='C')||(cs1=='C'&&cs2=='B')||(cs1=='C'&&cs2=='A')||(cs1=='A'&&cs2=='B')||(cs1=='D'&&cs2=='F')||(cs1=='F'&&cs2=='D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((cs1=='A'&&cs2=='B')||(cs1=='B'&&cs2=='A')||(cs1=='B'&&cs2=='C')||(cs1=='C'&&cs2=='B')||(cs1=='D'&&cs2=='F')||(cs1=='F'&&cs2=='D')) cout<<1;
	else cout<<0;
	return 0;
} 
