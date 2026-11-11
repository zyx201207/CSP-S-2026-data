#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,b;
	string a,c;
	cin>>n>>a>>b>>c;
	if(n==b){
		cout<<"1";
		if(a[1]==c[1]){
			cout<<"1";
			if(a[2]<='C'&&c[2]<='C'){
				cout<<"1";
				if(a[2]=='A'&&c[2]=='B'||a[2]=='B'&&c[2]=='A'||a[2]=='B'&&c[2]=='C'||a[2]=='C'&&c[2]=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				for(int i=0;i<2;i++){
					cout<<"0";
				}
			}
		}else{
			for(int i=0;i<3;i++){
				cout<<"0";
			}
		}
	}else{
		for(int i=0;i<4;i++){
			cout<<"0";
		}
	}
}