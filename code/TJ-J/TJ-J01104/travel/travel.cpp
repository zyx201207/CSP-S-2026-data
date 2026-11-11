#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	char n='0',m='1';
	if(a[0]==c[0]&&a[1]==c[1]){
		e.push_back(m); 
	}else{
			cout<<"0000";
		return 0;
	}
			
	
	if(b[0]==d[0]&&b[1]==d[1]){
			e.push_back(m);
	}else{
			cout<<"1000";
		return 0;
	}

	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		e.push_back(m);
		if(b[2]==d[2]+1||b[2]==d[2]-1){
			e.push_back(m);
		}else{
			e.push_back(n);
		}
	}else{
		if(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'){
		e.push_back(m);
		e.push_back(m); 
	}else{
		e.push_back(n);
		e.push_back(n);
	}
	}
	for(int i=0;i<4;i++){
		cout<<e[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
