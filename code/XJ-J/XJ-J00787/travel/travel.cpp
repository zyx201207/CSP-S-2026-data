#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	int e=1;
	if(a==b){
		cout<<e;
	}
	else {
		e=0;
		cout<<e;
	}
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<e;
	}
	else {
		e=0;
		cout<<e;
	}
	if(c[2]>='A'&&c[2]<='C'&&d[2]>='A'&&d[2]<='C'||c[2]=='D'||c[2]=='F'&&d[2]=='D'&&d[2]=='F'){
		cout<<e;
	}
	else {
		e=0;
		cout<<e;
	}
	if(c[2]==d[2]-1||c[2]==d[2]+1&&c[2]>='A'&&c[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		cout<<e;
	}
	else if(c[2]==d[2]-2||c[2]==d[2]+2&&c[2]=='D'||c[2]=='F'&&d[2]=='D'&&d[2]=='F'){
		cout<<e;
	}
	else{
		e=0;
		cout<<e;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}