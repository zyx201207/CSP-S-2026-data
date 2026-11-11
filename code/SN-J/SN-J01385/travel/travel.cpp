#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,d;
	string a,b;
	cin>>c>>a>>d>>b;
	if(c==d){
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(c==d&&a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
	} else {
		cout<<"0";
	}
	bool flag=false;
	if(a[2]<='C'&&b[2]<='C'){
		flag=true;
	} else if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')){
		flag=true;	
	}
	if(c==d&&a[0]==b[0]&&a[1]==b[1]&&flag==true){
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(c==d&&a[0]==b[0]&&a[1]==b[1]&&flag==true&&(a[2]=='C'&&b[2]=='D')||(b[2]=='C'&&a[2]=='D')){
		cout<<"0";
	} else if(c==d&&a[0]==b[0]&&a[1]==b[1]&&flag==true&&(a[2]+1==b[2]||a[2]-1==b[2])){
		cout<<"1";
	} else if(c==d&&a[0]==b[0]&&a[1]==b[1]&&flag==true&&(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='F')){
		cout<<"1";
	} else {
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
