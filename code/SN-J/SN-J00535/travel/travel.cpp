#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a!=x){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	if(b.substr(0,2)!=y.substr(0,2)){
		cout<<"000"<<endl;
		return 0;
	}
	cout<<"1";
	if(((b[2]=='D' or b[2]=='F') and (y[2]=='D' or y[2]=='F')) or ((b[2]=='A' or b[2]=='B' or b[2]=='C') and (y[2]=='A' or y[2]=='B' or y[2]=='C'))){
		cout<<"1";
	}
	else {
		cout<<"00"<<endl;
		return 0;
	}
	if(abs(b[2]-y[2])==1){
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}
