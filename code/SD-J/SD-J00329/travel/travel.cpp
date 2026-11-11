#include<bits/stdc++.h>
using namespace std;
char c1,c2,s1,s2;
int a[5]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		a[2]=1;
		a[3]=1;
	}else{
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}
	if(s1-'A'==s2-'B'||s1-'B'==s2-'A'||s1-'A'==s2-'C'||s1-'C'==s2-'A'||s1-'C'==s2-'B'||s1-'B'==s2-'C'||s1-'D'==s2-'F'||s1-'F'==s2-'D'){
		a[4]=1;
	}else{
		a[4]=0;
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}

