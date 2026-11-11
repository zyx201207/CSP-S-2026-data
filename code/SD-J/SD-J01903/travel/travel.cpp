#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		int p,q;
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			p=1;
		}
		else{
			p=2;
		}
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			q=1;
		}
		else{
			q=2;
		}
		if(p==q){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		int p,q;
		p=b[2]-'A';
		q=d[2]-'A';
		if(abs(p-q)==1&&!(p==2&&q==3)&&!(p==3&&q==2)){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
