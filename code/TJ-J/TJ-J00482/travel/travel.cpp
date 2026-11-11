#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool a1=1,a2=1,a3=1,a4=1;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			a2=false;
		}
	}
	if(!a2){
		cout<<"1000";return 0;
	}
	if(b[2]=='A'&&d[2]=='D'){
		a3=false;
	}
	if(b[2]=='A'&&d[2]=='F'){
		a3=false;
	}
	if(b[2]=='B'&&d[2]=='D'){
		a3=false;
	}
	if(b[2]=='B'&&d[2]=='F'){
		a3=false;
	}
	if(b[2]=='C'&&d[2]=='D'){
		a3=false;
	}
	if(b[2]=='C'&&d[2]=='F'){
		a3=false;
	}
	if(!a3){
		cout<<"1100";return 0;
	}
	
	if(b[2]+1!=d[2]&&b[2]-1!=d[2]){
		cout<<"1110";return 0;
	}
	else{
		cout<<"1111";return 0;
	}
	return 0;
} 
