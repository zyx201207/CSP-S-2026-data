#include<bits/stdc++.h>
using namespace std;
int r,x;
string s,v; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>s;
	cin>>x>>v;
	int p=10*s[0]+s[1];
	int m=10*v[0]+v[1];
	if(r==x){
		cout<<1;
		if(p==m){
			cout<<1;
			if(s[2]<='C'&&v[2]<='C'||s[2]>'C'&&v[2]>'C'){
				cout<<1;
				if(s[2]-v[2]==1||v[2]-s[2]==1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
} 
