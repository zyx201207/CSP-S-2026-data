#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[5],s2[5],c1[5],c2[5];
	int a=0,b=0,c=0;
	cin>>s1>>c1>>s2>>c2;	
	if(s1[0]==s2[0] && s1[1]==s2[1]) {
		cout<<1;
		a=1;
	}
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c1[0]+c1[1] == c2[0]+c2[1] && a==1){
		cout<<1;
		b=1;
	}
	else {
		cout<<0<<0<<0;
		return 0;
	}
	if(((c1[2]<='C' && c2[2]<='C') ||(c1[2]>='D' && c2[2]>='D')) && b==1){
		cout<<1;
		c=1;
	}
	else {
		cout<<0<<0;
		return 0;
	}
	if(c1[2]-c2[2]==1 || c1[2]-c2[2]==-1 && c==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}