#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int f[1001]={}; 
	if(a==c){
		f[1]==1;
		if(b[1]==d[1]){	
			if(b[2]==d[2]){
				f[2]==1;	
				if(b[3]=='D'&&d[3]=='F'||b[3]=='A'&&d[3]=='B'||b[3]=='A'&&d[3]=='C'||b[3]=='B'&&d[3]=='C'){
					f[3]==1;
				}
			} 
		}
	}
	cout<<f[1];
	cout<<f[2];
	cout<<f[3];
	cout<<f[4];
	return 0;
}


