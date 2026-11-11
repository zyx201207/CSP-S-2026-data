#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=(b[0]-'0')*10+(b[1]-'0');
	int y=(d[0]-'0')*10+(d[1]-'0');
	if(a==c){
		cout<<1;
		if(x==y){
			cout<<1;
			if(b[2]=='A' && (d[2]=='B' || d[2]=='C')){
				cout<<1;
				if(d[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(b[2]=='B' && (d[2]=='A' || d[2]=='C')){
				cout<<11;
			}else if(b[2]=='C' && (d[2]=='A' || d[2]=='B')){
				cout<<1;
				if(d[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(b[2]=='D' && d[2]=='E'){
				cout<<11;
			}else if(b[2]=='E' && d[2]=='D'){
				cout<<11;
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
}

