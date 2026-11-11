#include<bits/stdc++.h>
using namespace std;
bool v;
string a,b;
int m,n;
void blv(){
	if(a[2]=='D'){
		v=b[2]=='F';
	}
	if(a[2]=='F'){
		v=b[2]=='D';
	}
	if(a[2]=='A'){
		v=b[2]=='B';
	}
	if(a[2]=='B'){
		v=b[2]=='A'||b[2]=='C';
	}
	if(a[2]=='C'){
		v=b[2]=='B';
	}
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>a>>n>>b;
	blv();
	if(m==n){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			if((a[2]<'D'&&b[2]<'D')||(a[2]>'C'&&b[2]>'C')){
				cout<<1;
				if(v){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}	
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
