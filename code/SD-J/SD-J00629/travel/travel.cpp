#include<bits/stdc++.h>
using namespace std;
int v[5]={0,0,0,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	else if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
	}
	else if(v[b[2]-'A']!=v[d[2]-'A']){
		cout<<"1100";
	}
	else if(min(b[2],d[2])=='A'&&max(b[2],d[2])=='C'){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
}
