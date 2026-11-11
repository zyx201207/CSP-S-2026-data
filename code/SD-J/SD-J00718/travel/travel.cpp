#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<endl;
		return 0;
	}
	int s,t;
	s=(b[0]-'0')*10+(b[1]-'0');
	t=(d[0]-'0')*10+(d[1]-'0');
	if(s!=t){
		cout<<"1000"<<endl;
		return 0;
	}
	char l=b[2];
	char r=d[2];
	if(l<='C'&&r>'C'||l>'C'&&r<='C'){
		cout<<"1100"<<endl;
		return 0;
	}
	if(l+1==r||r+1==l)cout<<"1111"<<endl;
	else cout<<"1110"<<endl;
	return 0;
} 
//Trick||Treat!
