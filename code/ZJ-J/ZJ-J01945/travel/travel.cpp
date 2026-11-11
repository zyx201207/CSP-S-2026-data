#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}else{
		int a1,a2;
		char p1,p2;
		a1=(s1[0]-'0')*10+(s1[1]-'0');
		a2=(s2[0]-'0')*10+(s2[1]-'0');
		p1=s1[2];
		p2=s2[2];
		if(a1!=a2){
			cout<<"1"<<"0"<<"0"<<"0";
		}else if((p1<='C'&&p1>='A')&&(p2<='C'&&p2>='A')){
			if(p1+1==p2||p1-1==p2){
				cout<<"1"<<"1"<<"1"<<"1";
			}else{
				cout<<"1"<<"1"<<"1"<<"0";
			}
		}else if((p1<='F'&&p1>='D')&&(p2<='F'&&p2>='D')){
			cout<<"1"<<"1"<<"1"<<"1";
		}else{
			cout<<"1"<<"1"<<"0"<<"0";
		}
	}
	return 0;
}
