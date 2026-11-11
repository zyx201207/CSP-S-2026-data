#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool f=0,m=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1]&&r1==x1){
		cout<<1;
		f=1;
	}
	else{
		cout<<0;
	}
	if(f==1){
		if(r2[2]>='A'&&r2[2]<='C'){
			if(x2[2]>='A'&&x2[2]<='C'){
				cout<<1;
				m=1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if(m==1){
		if(r2[2]+1==x2[2]||r2[2]-1==x2[2]||x2[2]+1==r2[2]||x2[2]-1==r2[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 

