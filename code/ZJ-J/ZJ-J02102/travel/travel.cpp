#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,temp1,temp2;
char t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		temp1+=s1[0];
		temp1+=s1[1];
		temp2+=s2[0];
		temp2+=s2[1];
		if(temp1==temp2){
			cout<<"1";
			t1=s1[2];
			t2=s2[2];
			if(t1=='D'&&t2=='F') {
				cout<<"11";
			}else if(t1=='F'&&t2=='D'){
				cout<<"11";
			}else if(t1=='A'&&(t2=='B'||t2=='C')) {
				if(t2=='B') cout<<"11";
				else cout<<"10";
			}else if(t1=='B'&&(t2=='A'||t2=='C')) {
				cout<<"11";
			}else if(t1=='C'&&(t2=='B'||t2=='A')){
				if(t2=='B') cout<<"11";
				else cout<<"10";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}