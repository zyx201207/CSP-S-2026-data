#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
bool m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
			if(a1[i]!=b1[i]){
				cout<<0;
				m=1;
			}
		}
		if(m==0){
			cout<<1;
		}
		if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'&&b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
			cout<<1;
		}else if(a1[2]=='D'||a1[2]=='F'&&b1[2]=='D'||b1[2]=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
		if(a1[2]=='A'&&b1[2]=='B'||a1[2]=='B'&&b1[2]=='A'||a1[2]=='B'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='B'||a1[2]=='D'&&b1[2]=='F'||b1[2]=='A'&&a1[2]=='B'||b1[2]=='B'&&a1[2]=='A'||b1[2]=='B'&&a1[2]=='C'||b1[2]=='C'&&a1[2]=='B'||b1[2]=='D'&&a1[2]=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	return 0;
} 
