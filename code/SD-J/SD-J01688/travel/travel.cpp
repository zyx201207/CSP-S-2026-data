#include<bits/stdc++.h>
using namespace std;
string a1,a2;
string id1,id2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>id1>>a2>>id2;
	if(a1==a2){
		cout<<1;
		if(id1[0]==id2[0]&&id1[1]==id2[1]){
			cout<<1;
			if((id1[2]=='A'&&(id2[2]=='B'||id2[2]=='C'))||(id1[2]=='B'&&(id2[2]=='A'||id2[2]=='C'))||(id1[2]=='C'&&(id2[2]=='B'||id2[2]=='A'))||(id1[2]=='D'&&id2[2]=='E')||(id1[2]=='E'&&id2[2]=='D')){
				cout<<1;
				if((id1[2]=='A'&&id2[2]=='B')||(id1[2]=='B'&&(id2[2]=='A'||id2[2]=='C'))||(id1[2]=='C'&&id2[2]=='B')||(id1[2]=='D'&&id2[2]=='E')||(id1[2]=='E'&&id2[2]=='D')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
