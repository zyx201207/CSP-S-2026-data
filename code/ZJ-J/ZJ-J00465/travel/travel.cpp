#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else{
		if(b.substr(0,2)!=d.substr(0,2)) cout<<"1000";
		else{
			char x=b[2],y=d[2];
			if(x<='C'&&y>'C'||x>'C'&&y<'C') cout<<"1100";
			else if(x=='D'&&y=='F'||x=='F'&&y=='D'||abs(x-y)==1) cout<<"1111";
			else cout<<"1110";
		}
	} 
	return 0;
}
