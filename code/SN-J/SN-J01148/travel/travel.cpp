#include <bits/stdc++.h>
using namespace std;
int c1[3],c2[3];
string s1[4],s2[4];
int main (){
	/*
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	*/
	for(int i=0;i<2;i++){
		cin>>c1[i];
	}
	for(int j=1;j<=3;j++){
		cin>>s1[j];
	}
//	for(int n=1;n<=2;n++){
//		cin>>c2[n];
//	}
//	for(int m=1;m<=3;m++){
//		cin>>s2[m];
//	}
	for(int i=0;i<2;i++){
		cout<<c1[i];
	}
	for(int j=1;j<=3;j++){
		cout<<s1[j];
	}
//	for(int n=1;n<=2;n++){
//		cout<<c2[n];
//	}
//	for(int m=1;m<=3;m++){
//		cout<<s2[m];
//	}
	/*
	if(c1==c2){
		cout<<1;
	}
	if((a[1]==b[1] and a[2]==b[2])or(a[1]==0 and b[1]==0 and a[1]==b[1])){
		cout<<1; 
	}
	*/
	return 0;
}
