#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	int x;
	cin>>a>>c>>b>>d;
	if(a==b){
		x=1110;
	}
	else{
		cout<<"000";
	}
	if(x==1110){
		
		if(d[0]!=c[0]||d[1]!=c[1]){
			x=1000;
		}
		else if(d[2]=='C'&&c[2]=='D'||d[2]=='D'&&c[2]=='C'){
			x=1100;
		}
		else if(d[2]-c[2]==1){
			x=1111;
		}
		else if(d[2]=='F'&&c[2]=='D'||d[2]=='D'&&c[2]=='F'){
			x=1111;
		}
		else if(d[2]-c[2]!=1){
			x=1110;
		}
		
		else{
			x=1111;
		}
	}
	cout<<x;
	return 0;
}