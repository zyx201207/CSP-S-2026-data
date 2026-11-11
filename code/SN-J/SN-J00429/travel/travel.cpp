#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ch1,s1,ch2,s2;
	cin>>ch1>>s1>>ch2>>s2;
	int a1=(ch1[0]-48)*10+ch1[1]-48,a2=(ch2[0]-48)*10+ch2[1]-48;
	char c1=s1[2],c2=s2[2];
	int b1=(s1[0]-48)*10+s1[1]-48,b2=(s2[0]-48)*10+s2[1]-48;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}else{
		if(b1!=b2){
			cout<<"1000";
			return 0;
		}else{
			if(!((c1>='A'&&c1<='C'&&c2>='A'&&c2<='C')||((c1=='D'||c1=='F')&&(c2=='D'||c2=='F')))){
				cout<<"1100";
				return 0;
			}else{
				if(!((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')||(c1=='C'&&c2=='B')||(c1=='B'&&c2=='C')||(c1=='F'&&c2=='D')||(c1=='D'&&c2=='F'))){
					cout<<"1110";
					return 0;
				}else{
					cout<<"1111";
				}
			}
		}
	}
	return 0;
}
