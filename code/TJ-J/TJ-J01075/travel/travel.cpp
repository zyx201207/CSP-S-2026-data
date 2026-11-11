#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int s=0,z=0;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C'){
			    s+=1;
				cout<<1;
				if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'){
				    cout<<0;}
				    else{
				    	cout<<1;
					}}
			else if(b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F'){
				    s+=1;
					cout<<1<<1;
				}
	       if(s==0){
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
		}
	
	else{
		cout<<0<<0<<0<<0;
	}

}
