#include<bits/stdc++.h>
using namespace std;
int c1,c2,n,m;
string s1,s2;
int f(){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		n=1;
	}else{
		n=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		m=1;
	}else{
		m=2;
	}
	if(n==m){
		return 1;
	}else{
		return 0;
	}
}
int h(){
	if(s1[2]=='B'||s2[2]=='B'){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"1000";
		}else{
			if(f()==0){
				cout<<"1100";
			}else{
				if(n==2&&m==2){
					cout<<"1111";
				}else if(n==1&&m==1&&h()==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}
		}
	}
} 
