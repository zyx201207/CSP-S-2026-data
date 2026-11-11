#include<bits/stdc++.h>
using namespace std;
string a[2],b[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>b[0]>>a[1]>>b[1];
	if(a[0]==a[1]){
		cout<<1;
		if(b[0][0]==b[1][0]&&b[0][1]==b[1][1]){
			cout<<1;
			if(b[0][2]<='C'&&b[1][2]<='C'){
				cout<<1;
				if(abs(b[0][2]-b[1][2])==1){
					cout<<1;
				}
				else cout<<0;
			}
			else if(b[0][2]>'C'&&b[1][2]>'C'){
				cout<<11;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else{
		cout<<0<<0<<0<<0;
	}
}
