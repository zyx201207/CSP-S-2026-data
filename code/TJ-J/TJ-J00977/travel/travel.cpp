#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>a;
//vector<int>s;
string a,b,c,d;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		e=b[2];
		f=d[2];
		b=(b[0]+b[1]);
		d=(d[0]+d[1]);
		if(b==d){
			cout<<1;
			if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='A'&&f=='C')||(e=='C'&&f=='A')||(e=='C'&&f=='B')||(e=='B'&&f=='C')||(e=='D'&&f=='F')||(e=='F'&&f=='D')){
				cout<<1;
				if(abs(e-f)==1&&e!='D'&&e!='F'&&f!='D'&&f!='F'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
