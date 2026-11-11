#include<bits/stdc++.h>
using namespace std;
int q,p;
string a,c,b,d;
int mu=0,ma=9;
int main(){
	freopen("travel.in","r",stdin);		
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
		if(a==c){
			cout<<1;
		}
		else{
			cout<<0<<0<<0<<0;
			return 0;
		}


	//1

	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		if(b[2]=='F'||b[2]=='D'){
			ma=1;
		}
		else{
			ma=2;
		}
		if(d[2]=='F'||d[2]=='D'){
			mu=1;
		}
		else{
			mu=2;
		}
		if(ma==1&&mu==1){
			cout<<1<<1;
			return 0;
		}
		if(ma==mu){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0;
		cout<<0;
	}
	if(d[2]=='D'&&b[2]=='C'){
		cout<<0;
		return 0;
	}
	if(d[2]=='C'&&b[2]=='D'){
		cout<<0;
		return 0;
	}
	if(d[2]-b[2]==1||d[2]-b[2]==-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;

	
	
}

