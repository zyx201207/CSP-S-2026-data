#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[3],s2[3];
	int  a[4]={0,0,0,0};
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F'){
		s1[2]='E';
	}
	if(s2[2]=='F'){
		s2[2]='E';
	}
	if(c1==c2){
		a[0]=1;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		a[1]=1;
	}
	if(s1[2]-64<=3 && s2[2]-64<=3 ){
		a[2]=1;
	}else if(s1[2]-64>3 && s2[2]-64>3){
		a[2]=1;
	}
	if(s1[2]+1==s2[2]+0){
		a[3]=1;
	}else if( s1[2]-1==s2[2]+0){
		a[3]=1;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
