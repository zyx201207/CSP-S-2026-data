#include<bits/stdc++.h>
using namespace std;
char a[15],b[15]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=5;++i){
		cin>>a[i];
	}
	for(int i=1;i<=5;++i){
		cin>>b[i];
	}
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]){
		if((a[5]<='C'&&b[5]<='C')||(a[5]>'C'&&b[5]>'C')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]){
		if((a[5]<='C'&&b[5]<='C')||(a[5]>'C'&&b[5]>'C')){
			char c=a[5],cc=b[5];
			if((c=='A'&&cc=='B')||(c=='B'&&cc=='C')||(c=='D'&&cc=='F')||(cc=='A'&&c=='B')||(cc=='B'&&c=='C')||(cc=='D'&&c=='F')){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
