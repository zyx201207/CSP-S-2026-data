#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,z1,z2;
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2){//1 
		cout<<1;
	} else cout<<0;
	
	if(c1==c2&&z1[0]==z2[0]&&z1[1]==z2[1]){//2
		cout<<1;
	}else cout<<0;
	
	char q1=z1[2],q2=z2[2],p1,p2;
	if(q1=='A'||q1=='B'||q1=='C'){
		p1='l';
	}else p1='r';
	if(q2=='A'||q2=='B'||q2=='C'){
		p2='l';
	}else p2='r';
	if(z1[0]==z2[0]&&z1[1]==z2[1]&&c1==c2&&p1==p2){//3
		cout<<1;
	}else cout<<0;
	
	if(z1[0]==z2[0]&&z1[1]==z2[1]&&c1==c2&&p1==p2&&abs(q1-q2)==1){
		if((q1=='C'&&q2=='D')||(q2=='C'&&q2=='D')){
			cout<<0;
		}else cout<<1;
	}else cout<<0;
	return 0;
}

