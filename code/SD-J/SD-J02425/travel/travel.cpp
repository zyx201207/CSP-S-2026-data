#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		int a=(a2[0]-'0')*10+(a2[1]-'0');
		int b=(b2[0]-'0')*10+(b2[1]-'0');
		if(a==b){
			cout<<1;
			char x=a2[2],y=b2[2];
			if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
				cout<<1;
				if(x+1==y&&x!='C'||x-1==y&&x!='D'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(x>='D'&&x<='F'&&y>='D'&&y<='F'&&x!='E'&&y!='E'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
