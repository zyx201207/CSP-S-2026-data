#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	int j=1;
	int k=1;
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
	cout<<"1";
	
	}else{
		
		cout<<"0000";
		return 0;
	}
	
	if(b[0]==d[0]&&b[1]==d[1]){
		j=0;
		cout<<"1";	
	}else cout<<"0";
	
	if(j==0&&b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||j==0&&b[2]=='F'&&d[2]=='D'||j==0&&b[2]=='D'&&d[2]=='F'){
		k=0;
		cout<<"1";
	}else cout<<"0";
	
	
	if(k==0&&b[2]+2==d[2]||k==0&&b[2]-2==d[2])cout<<"1";
	else cout<<"0";
	
	
}