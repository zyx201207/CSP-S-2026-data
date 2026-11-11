#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char x,y;
			if(s1[2]>s2[2]){
				x=s2[2];
				y=s1[2];
			}else{
				x=s1[2];
				y=s2[2];
			}
			if(y!='D'&&y!='F'||x=='D'&&y=='F'){
				cout<<1;
				if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F'){
					cout<<1;
				}else{
					cout<<0;
				}
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
