#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
	}else if((b[2]>='D'&&d[2]<'D'||(b[2]<='C'&&d[2]>'C'))){
		cout<<"1100";
	}else if(int(b[2])+1!=int(d[2])&&int(b[2])-1!=int(d[2])){
		cout<<"1110";
	}else cout<<"1111";
	return 0;
} 
//8:52 so easy
