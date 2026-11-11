#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,f=1;
	string b_,d_;
	cin>>a>>b_>>c>>d_;
	b=b_[0]*10+b_[1];
	d=d_[0]*10+d_[1];
	if(a==c){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	if(b==d){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	if(((b_[2]=='A'||b_[2]=='B'||b_[2]=='C')&&(d_[2]=='A'||d_[2]=='B'||d_[2]=='C'))||((b_[2]=='D'||b_[2]=='F')&&(d_[2]=='D'||d_[2]=='F'))){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	if((b_[2]=='A'&&d_[2]=='B')||(b_[2]=='B'&&d_[2]=='A')||(b_[2]=='B'&&d_[2]=='C')||(b_[2]=='C'&&d_[2]=='B')||(b_[2]=='D'&&d_[2]=='F')||(b_[2]=='F'&&d_[2]=='D')){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	return 0;
}
