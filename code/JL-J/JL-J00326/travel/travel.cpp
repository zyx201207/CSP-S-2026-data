#include <bits/stdc++.h>
using namespace std;
string s,t,x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>x>>t>>y;
	if(s==t){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0]&&x[1]==y[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((x[2]<='C'&&y[2]<='C')||(x[2]>='D'&&y[2]>='D')){
		cout<<"1";	
	}else{
		cout<<"00";
		return 0;
	}
	if((x[2]<='C'&&y[2]<='C'&&abs(x[2]-y[2])==1)||(x[2]>='D'&&y[2]>='D'&&abs(x[2]-y[2])==2)){
		cout<<"1";	
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
