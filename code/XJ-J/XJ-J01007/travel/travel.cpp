#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f=1,a=1,s=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		f=0;
		cout<<0;
	}
	if(f==1 && s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		a=0;
		cout<<0;
	}
	if(f==1 && a==1 && (s1[2]>='A') && (s2[2]<='C') || (s1[2]>='D') && (s2[2]<='F')){
		cout<<1;
	}else{
		s=0;
		cout<<0;
	}
	if(f==1 && a==1 && s==1 && (s1[2]+1==s2[2] || s1[2]-1==s2[2]) || (s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}