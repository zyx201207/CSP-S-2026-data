#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		int c=(c2[0]-'0')*10+(c2[1]-'0');
		int s=(s2[0]-'0')*10+(s2[1]-'0');
		if(c==s){
			cout<<1;
			if((c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D')){
				cout<<1;
			}else if(c2[2]=='D'||c2[2]=='F'||s2[2]=='D'||s2[2]=='F'){
				cout<<0;
			}else{
				cout<<1;
			}
			int a=c2[2]-'A';
			int b=s2[2]-'A';
			if((c2[2]=='C'&&s2[2]=='D')||(c2[2]=='D'&&s2[2]=='C')){
				cout<<0;
			}else if((abs(a-b)==1)||(c2[2]=='F'&&s2[2]=='D')||(c2[2]=='D'&&s2[2]=='F')){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}