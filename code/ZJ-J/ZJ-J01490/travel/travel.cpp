#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if((b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0'){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]-'A'<=2 && d[2]-'A'<=2) || (b[2]-'A'>2 && d[2]-'A'>2)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
} 
