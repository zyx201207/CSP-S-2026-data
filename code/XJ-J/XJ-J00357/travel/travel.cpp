#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[4]={0,0,0,0};
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int r=s1[0]+s1[1],r1=s2[0]+s2[1];
	if(c1==c2){
		a[0]=1;
	}
	if(a[0]==1&&r==r1){
		a[1]=1;
	}
	char c=s1[2],d=s2[2];
	if(a[1]==1&&((c>='A'&&c<='C')&&(d>='A'&&d<='C'))||((c>='D'&&c<='F')&&(d>='d'&&d<='F'))){
		a[2]=1;
	}
	if(a[2]==1&&c>='D'&&c<='F'){
		if(abs(d-c)==2){
			a[3]=1;
		}
	}else if(a[2]==1){
		if(abs(d-c)==1){
			a[3]=1;
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}