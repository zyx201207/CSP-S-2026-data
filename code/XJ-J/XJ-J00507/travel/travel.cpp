#include<bits/stdc++.h>
using namespace std;
int a,c,la;
string b,d,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	} 
	if(b[1]!=d[1]||b[0]!=d[0]){
		cout<<"1000";
		return 0;
	}
	if(b[2]=='D'&&d[2]=='C'){            
		cout<<"1100";                  
		return 0;
	}else if(b[2]=='C'&&d[2]=='D'){            
		cout<<"1100";                  
		return 0;
	}else if(b[2]=='D'||b[2]=='F'){            
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			cout<<"1100";                  
			return 0;
		}
	}else if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(b[2]=='D'||b[2]=='F'){            
			cout<<"1100";
			return 0;
		}
	}
	if(b[2]=='D'&&d[2]=='F'){            
		cout<<"1111";                  
		return 0;
	}else if(b[2]=='F'&&d[2]=='D'){            
		cout<<"1111";                  
		return 0;
	}else if(abs(b[2]-d[2])!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
  	fclose(stdin);
	fclose(stdout);
	return 0;
}
