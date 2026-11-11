#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,a,x2,b;cin>>x1>>a>>x2>>b;
	char a1=a[2],b1=b[2];
	if(x1==x2){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			if(a1=='A'&&b1=='B'){
				cout<<1;
				cout<<1;
			}
			else if(a1=='B'&&b1=='C'){
				cout<<1;
				cout<<1;
			}
			else if(a1=='A'&&b1=='C'){
				cout<<1;
				cout<<0;
			}
			else if(a1=='D'&&b1=='F'){
				cout<<1;
				cout<<1;
			}
			else if(a1=='B'&&b1=='A'){
				cout<<1;
				cout<<1;
			}
			else if(a1=='C'&&b1=='B'){
				cout<<1;
				cout<<1;
			}
			else if(a1=='C'&&b1=='A'){
				cout<<1;
				cout<<0;
			}
			else if(a1=='F'&&b1=='D'){
				cout<<1;
				cout<<1;
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
		
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
} 
