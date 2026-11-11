#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char x[4],y[4];
	cin>>a>>x[1]>>x[2]>>x[3]>>b>>y[1]>>y[2]>>y[3];
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if((x[1]==y[1])&&(x[2]==y[2])){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(x[3]=='A'){
		if(y[3]=='B'){
			cout<<"11";
			return 0;
		}
		if(y[3]=='C'){
			cout<<"10";
			return 0;
		}
		cout<<"00";
		return 0;
	}
	if(x[3]=='B'){
		if(y[3]=='A'||y[3]=='C'){
			cout<<"11";
			return 0;
		}
		cout<<"00";
		return 0;
	}
	if(x[3]=='C'){
		if(y[3]=='B'){
			cout<<"11";
			return 0;
		}
		if(y[3]=='A'){
			cout<<"10";
			return 0;
		}
		cout<<"00";
		return 0;
	}
	if(x[3]=='D'){
		if(y[3]=='F'){
			cout<<"11";
			return 0;
		}
		cout<<"00";
		return 0;
	}
	if(x[3]=='F'){
		if(y[3]=='D'){
			cout<<"11";
			return 0;
		}
		cout<<"00";
		return 0;
	}
	return 0;
}
