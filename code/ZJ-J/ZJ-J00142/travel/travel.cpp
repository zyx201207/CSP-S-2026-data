#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	char cx=sa[2],cy=sb[2];
	if(ca!=cb){
		cout<<"0000";
	}
	else if(sa[0]!=sb[0]||sa[1]!=sb[1]){
		cout<<"1000";
	}
	else if(((cx=='A'||cx=='B'||cx=='C')&&(cy=='D'||cy=='E'))||((cx=='D'||cx=='E')&&(cy=='A'||cy=='B'||cy=='C'))){
		cout<<"1100";
	}
	else if(((cx=='A'||cx=='C')&&cy!='B')||(cx=='B'&&(cy!='A'||cy!='C'))||(cx=='D'&&cy!='E')||(cx=='E'&&cy!='D')){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
return 0;
}