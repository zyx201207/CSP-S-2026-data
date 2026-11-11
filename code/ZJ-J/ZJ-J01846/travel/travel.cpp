#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int h=1;
	for(int i=0;i<b.size()-1;i++){
		if(b[i]!=d[i]){
			h=0;
			break;
		}
	}
	if(h==0){
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	else{
		cout<<1;
	}
	char f1=b[b.size()-1];
	char f2=d[d.size()-1];
	if((f1=='A'&&f2=='B')||(f1=='B'&&f2=='A')||(f1=='A'&&f2=='C')||(f1=='C'&&f2=='A')||(f1=='B'&&f2=='C')||(f1=='C'&&f2=='B')||(f1=='D'&&f2=='F')||(f1=='F'&&f2=='D')){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if((f1=='A'&&f2=='B')||(f1=='B'&&f2=='A')||(f1=='B'&&f2=='C')||(f1=='C'&&f2=='B')||(f1=='D'&&f2=='F')||(f1=='F'&&f2=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
}