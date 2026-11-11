#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ca,cb,paia,paib,ja=0,jb=0;
	string sa,sb;
	cin>>ca>>sa>>cb>>sb;
	int changa=sa.size()-1;
	int changb=sb.size()-1;
	if(ca==cb){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	for(int i=0;i<sa.size()-1;i++){
		paia=sa[i];
	}
	for(int i=0;i<sb.size()-1;i++){
		paib=sb[i];
	}
	if(paia==paib){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(sa[changa]=='A'||sa[changa]=='B'||sa[changa]=='C'){
		ja=1;
	}
	if(sb[changb]=='A'||sb[changb]=='B'||sb[changb]=='C'){
		jb=1;
	}
	if((ja==jb)&&(jb==1)){
		cout<<1;
		if((sa[changa]=='A'&&sb[changb]=='C')||(sa[changa]=='C'||sb[changb]=='A')){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	else if((ja==jb)&&(jb==0)){
		cout<<1;
		cout<<1;
		return 0;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
}
